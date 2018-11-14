#include<stdlib.h>
#include<GLUT/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>

using namespace std;
float x, y, theta;
void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 1000);
}

void house()
{
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(200, 200);
    glVertex2f(150, 150);
    glVertex2f(150, 50);
    glVertex2f(250, 50);
    glVertex2f(250, 150);
    glEnd();
    
   glBegin(GL_LINE_LOOP);
    glVertex2f(190, 50);
    glVertex2f(190, 90);
    glVertex2f(210, 90);
    glVertex2f(210, 50);
    glEnd();
}
void drawing()
{
    house();
    glTranslatef(x,y, 0);
    glRotatef(theta, 0.0, 0.0, 1.0);
    glTranslatef(-x,-y, 0);
    house();
    glFlush();
}
int main(int argc, char** argv)
{
    cout<<"Enter fixed point about which to rotate and angle in degrees\n";
    cin>>x>>y>>theta;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("House rotate");
    glutDisplayFunc(drawing);
    init();
    glutMainLoop();
    return 0;
}
