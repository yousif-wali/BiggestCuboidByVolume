/*
*   Correct me if I am wrong:
*   The program is working with 4 3D points in an array
*   then it connects the points in such as A-B, B-C, and A-D
*   and it will find the distance between each points
*   in such that AB -> BC can make a rectangle, because
*   AB = CE && BC = AE where E is the same length away form
*   point C just like A to B.
*
*   Then the distance between A to D would make the cuboid.
*   There it will make width,height,and length which is necessary
*   To find out the volume of the cuboid.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double findDistance(int x1, int y1, int z1, int x2, int y2, int z2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
}
int main() {
    cout << showpoint << fixed << setprecision(2);
    int cubes[4][4][3] = {
    {{4,5,6},{9,3,2},{7,1,6},{8,3,1}},
    {{6,5,2},{-1,3,-6},{-4,9,3},{-9,3,8}},
    {{-9,8,5},{5,10,2},{11,-1,9},{5,5,1}},
    {{-4,2,-5},{-3,-9,1},{8,5,3},{4,-1,0}} };
    int volumes[4];
    int highest = 0;
    for (int i = 0; i < 4; i++) {
        double distanceAB = 0;
        double distanceBC = 0;
        double distanceAD = 0;

        distanceAB = findDistance(cubes[i][0][0], cubes[i][0][1], cubes[i][0][2],
            cubes[i][1][0], cubes[i][1][1], cubes[i][1][2]);

        distanceBC = findDistance(cubes[i][1][0], cubes[i][1][1], cubes[i][1][2],
            cubes[i][2][0], cubes[i][2][1], cubes[i][2][2]);

        distanceAD = findDistance(cubes[i][0][0], cubes[i][0][1], cubes[i][0][2],
            cubes[i][3][0], cubes[i][3][1], cubes[i][3][2]);
        double volume = distanceAB * distanceBC * distanceAD;
        volumes[i] = volume;
        if (volumes[highest] < volumes[i]) {
            highest = i;
        }
        cout << "volumes[" << i << "] = " << volumes[i] << endl;
    }
    switch (highest) {
    case 0:
        cout << "The biggest cuboid by volume was the first cuboid.";
        break;
    case 1:
        cout << "The biggest cuboid by volume was the second cuboid.";
        break;
    case 2:
        cout << "The biggest cuboid by volume was the third cuboid.";
        break;
    case 3:
        cout << "The biggest cuboid by volume was the fourth cuboid.";
        break;
    default:
        cout << "Something went wrong";
    }
    return 0;
}