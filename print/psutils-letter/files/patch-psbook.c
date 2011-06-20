--- psbook.c.orig	2011-06-21 04:19:12.000000000 +0900
+++ psbook.c	2011-06-21 04:19:36.000000000 +0900
@@ -32,7 +32,7 @@
 }
 
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
    int signature = 0;
    int currentpg, maxpage;
@@ -107,5 +107,5 @@
    }
    writetrailer();
 
-   exit(0);
+   return (0);
 }
