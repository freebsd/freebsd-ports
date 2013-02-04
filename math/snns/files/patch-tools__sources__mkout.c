--- tools/sources/mkout.c.orig	2008-04-21 16:56:08.000000000 +0900
+++ tools/sources/mkout.c	2012-10-24 04:38:57.000000000 +0900
@@ -26,7 +26,7 @@
 
 #define RAWNUM 8
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 
 {
    int i, units, active;
