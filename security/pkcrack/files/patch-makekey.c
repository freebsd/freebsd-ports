--- ./makekey.c.orig	2003-01-01 16:49:51.000000000 +0100
+++ ./makekey.c	2011-06-21 16:03:52.000000000 +0200
@@ -12,6 +12,7 @@
 
 #include <stdio.h>
 #include <string.h>
+#include <stdlib.h>
 #include "pkcrack.h"
 #include "keystuff.h"
 #include "crc.h"
@@ -24,7 +25,7 @@
     exit( 1 );
 }
 
-void main( int argc, char **argv )
+int main( int argc, char **argv )
 {
 char *	pwd;  
 int	pwdLen, i;
@@ -41,5 +42,6 @@
 	updateKeys( pwd[i] );
 
     printf( "%08x %08x %08x\n", key0, key1, key2 );
+    return(0);
 }
 
