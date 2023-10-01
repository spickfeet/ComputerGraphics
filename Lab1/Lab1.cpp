#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <glut.h>

void resize(int width, int height)
{
}


void  display(void)
{
    //glColor3d(1, 1, 0);
    //glutSolidTeapot(2);
    //glutSolidSphere(1,20,20);
    //glutWireSphere(2, 20, 20);
    //glutSolidCube(2);
    //glutWireCube(2);
    //glutSolidTorus(1, 3, 20, 20);
    //glutWireTorus(2, 3, 20, 20);
    glLineWidth(2);       // ширину линии 
    // устанавливаем 1
 

    glViewport(0,0,300,300);
    glPointSize(6);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);

    glColor3d(0, 0, 1);
    glVertex2d(-5, -5); // точка синяя

    glColor3d(1, 1, 0);     // точка желтая
    glVertex2d(-3, 4);
    glEnd();

    glDisable(GL_POINT_SMOOTH);
    glPointSize(6);
    glBegin(GL_POINTS);

    glColor3d(0, 1, 0);
    glVertex2d(3, -4);   // точка зеленая

    glColor3d(1, 0, 0);     // точка третья 
    glVertex2d(3, 3);  
    glEnd();

    glViewport(0, 300, 300, 300);

    glLineWidth(1);       // ширину линии 
    glBegin(GL_LINES);
    glColor3d(1, 1, 0);    
    glVertex2d(-5, -1); // желтая линия
    glVertex2d(4, 5);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3d(0, 1, 0);
    glVertex2d(-2, -2); // зеленая линия
    glVertex2d(5, 3);
    glEnd();

    glLineWidth(1);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_LINE_STIPPLE); // разрешаем рисовать прерывистую линию
    glLineStipple(3, 0x1c47);    // устанавливаем маску
    glBegin(GL_LINES);
    glColor3d(1, 0, 0);

    glVertex2d(5, -3); // красная линия
    glVertex2d(-4, 4);

    glEnd();

    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_LINE_STIPPLE);


    glViewport(300, 0, 300, 300);

    glFlush();

}
void init(void)
{
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-6, 6, -6, 6, 0, 6);

    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 10);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Hello");
    glutReshapeFunc(resize);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
