--- psnup.c.orig	2011-06-21 04:22:34.000000000 +0900
+++ psnup.c	2011-06-21 04:22:46.000000000 +0900
@@ -66,7 +66,7 @@
    return (0);
 }
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
    int horiz, vert, rotate, column, flip, leftright, topbottom;
    int nup = 1;
@@ -331,6 +331,6 @@
       pstops(nup, 1, 0, specs, draw);		/* do page rearrangement */
    }
 
-   exit(0);
+   return (0);
 }
 
