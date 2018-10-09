--- src/eigs/primme_interface.c.orig	2018-10-08 17:26:04 UTC
+++ src/eigs/primme_interface.c
@@ -36,7 +36,7 @@
  *
  ******************************************************************************/
 
-#if !(defined (__APPLE__) && defined (__MACH__))
+#if !(defined (__APPLE__) && defined (__MACH__)) && !defined(__FreeBSD__)
 #  include <malloc.h>
 #endif
 #include <stdlib.h>   /* mallocs, free */
