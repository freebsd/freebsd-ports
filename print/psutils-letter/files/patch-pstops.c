--- pstops.c.orig	2011-06-21 04:21:27.000000000 +0900
+++ pstops.c	2011-06-21 04:21:41.000000000 +0900
@@ -112,7 +112,7 @@
    return (head);
 }
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
    PageSpec *specs = NULL;
    int nobinding = 0;
@@ -194,5 +194,5 @@
 
    pstops(modulo, pagesperspec, nobinding, specs, draw);
 
-   exit(0);
+   return (0);
 }
