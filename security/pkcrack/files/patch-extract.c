--- ./extract.c.orig	2003-01-01 16:49:51.000000000 +0100
+++ ./extract.c	2011-06-21 16:03:11.000000000 +0200
@@ -68,7 +68,6 @@
 #endif
 
 #include <fcntl.h>
-#include <malloc.h>
 #include <string.h>
 
 #include "headers.h"
@@ -90,7 +89,7 @@
     fprintf( stderr, " -s <size>\textract only specified number of bytes\n" );
 }
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
 char	*ret, *outname;
 int	outfile, err=0, i, caseflg=0, size=0;
@@ -150,5 +149,5 @@
     }
     free( ret );
   }
-  exit(err);
+  return(err);
 }
