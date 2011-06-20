--- psselect.c.orig	2011-06-21 04:20:51.000000000 +0900
+++ psselect.c	2011-06-21 04:21:08.000000000 +0900
@@ -91,7 +91,7 @@
 }
 
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
    int currentpg, maxpage = 0;
    int even = 0, odd = 0, reverse = 0;
@@ -235,5 +235,5 @@
    }
    writetrailer();
 
-   exit(0);
+   return (0);
 }
