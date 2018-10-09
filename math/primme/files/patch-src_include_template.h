--- src/include/template.h.orig	2018-10-08 17:27:07 UTC
+++ src/include/template.h
@@ -368,7 +368,7 @@
  *
  **********************************************************************/
 
-#if !(defined (__APPLE__) && defined (__MACH__))
+#if !(defined (__APPLE__) && defined (__MACH__)) && !defined(__FreeBSD__)
 #  include <malloc.h> /* malloc */
 #endif
 #include <stdlib.h>   /* malloc, free */
