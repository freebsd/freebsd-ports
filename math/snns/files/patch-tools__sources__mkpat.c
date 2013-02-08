--- tools/sources/mkpat.c.orig	2008-04-21 16:56:08.000000000 +0900
+++ tools/sources/mkpat.c	2012-10-24 04:40:37.000000000 +0900
@@ -25,7 +25,7 @@
 
 #define RAWNUM 8
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 
 {
    int i;
