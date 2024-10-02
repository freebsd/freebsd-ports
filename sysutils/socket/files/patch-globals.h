--- globals.h.orig
+++ globals.h
@@ -48,7 +48,7 @@
 void strip_crs A((char *from, char *to, int *sizep)) ;
 void background A((void)) ;
 
-extern int errno ;
+#include <errno.h>
 
 /* global variables */
 extern int serverflag ;
