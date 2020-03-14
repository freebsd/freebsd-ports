--- src/rawformats.c.orig	2008-01-08 16:52:56 UTC
+++ src/rawformats.c
@@ -31,6 +31,7 @@
  */
 
 #define X_DISPLAY_MISSING
+#include <sys/types.h>
 #include <Imlib2.h>
 #include <string.h>
 #include <stdlib.h>
