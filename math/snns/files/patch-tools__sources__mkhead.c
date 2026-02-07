--- tools/sources/mkhead.c.orig	2008-04-21 16:56:08.000000000 +0900
+++ tools/sources/mkhead.c	2012-10-24 04:36:51.000000000 +0900
@@ -25,7 +25,7 @@
 #include <time.h>
 
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 
 {
    time_t t;
