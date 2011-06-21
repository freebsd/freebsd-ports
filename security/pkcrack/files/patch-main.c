--- ./main.c.orig	2003-01-01 16:49:51.000000000 +0100
+++ ./main.c	2011-06-21 16:03:11.000000000 +0200
@@ -80,7 +80,6 @@
 
 #include <sys/stat.h>
 #include <fcntl.h>
-#include <malloc.h>
 #include <stdlib.h>
 #include <string.h>
 
@@ -128,7 +127,7 @@
     fprintf( stderr, " -n\tno progress indicator\n" );
 }
 
-void main( int argc, char **argv )
+int main( int argc, char **argv )
 {
 int		crypt, plain, cryptlength, plainlength;
 struct stat	filestat;
@@ -334,5 +333,5 @@
     now = time(NULL);
     fprintf( stderr, "Finished on %s", ctime(&now) );
 
-    exit(0);
+    return(0);
 }
