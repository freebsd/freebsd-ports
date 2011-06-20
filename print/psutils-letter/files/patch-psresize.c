--- psresize.c.orig	2011-06-21 04:23:10.000000000 +0900
+++ psresize.c	2011-06-21 04:23:27.000000000 +0900
@@ -46,7 +46,7 @@
 #define MIN(x,y) ((x) > (y) ? (y) : (x))
 #define MAX(x,y) ((x) > (y) ? (x) : (y))
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
    double scale, rscale;			/* page scale */
    double waste, rwaste;			/* amount wasted */
@@ -175,6 +175,6 @@
       
    pstops(1, 1, 0, specs, 0.0);		/* do page rearrangement */
 
-   exit(0);
+   return (0);
 }
 
