--- epsffit.c.org	2011-06-21 04:22:01.000000000 +0900
+++ epsffit.c	2011-06-21 04:22:16.000000000 +0900
@@ -39,7 +39,7 @@
    exit(1);
 }
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
    int bbfound = 0;              /* %%BoundingBox: found */
    int urx, ury, llx, lly;
@@ -185,5 +185,5 @@
    } else
       message(FATAL, "no %%%%BoundingBox:\n");
 
-   exit(0);
+   return (0);
 }
