--- src/Main.c.orig	1997-05-21 18:25:09.000000000 +0200
+++ src/Main.c	2011-09-12 22:40:50.000000000 +0200
@@ -391,7 +391,7 @@
   Main function
 ---------------------------------------------------------------------------*/
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
   char *s, *buf;
   int bufsize;
