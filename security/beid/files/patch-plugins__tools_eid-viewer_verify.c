--- plugins_tools/eid-viewer/verify.c.orig	2021-08-13 09:34:02 UTC
+++ plugins_tools/eid-viewer/verify.c
@@ -19,7 +19,6 @@
 #endif
 
 #ifdef HAVE_LIBBSD
-#include <bsd/bsd.h>
 #endif
 
 #ifdef __APPLE__
