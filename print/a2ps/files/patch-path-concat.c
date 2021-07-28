--- lib/path-concat.c.orig	1999-10-10 18:34:46 UTC
+++ lib/path-concat.c
@@ -31,7 +31,7 @@
 #endif
 #include <sys/types.h>
 
-char *malloc ();
+#include <stdlib.h>
 
 #ifndef DIRECTORY_SEPARATOR
 # define DIRECTORY_SEPARATOR '/'
