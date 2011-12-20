--- src/framework/mlt_property.h.orig	2011-10-31 21:26:04.000000000 +0400
+++ src/framework/mlt_property.h	2011-12-12 22:55:02.000000000 +0400
@@ -26,7 +26,11 @@
 
 #include "mlt_types.h"
 
-#if defined(__GLIBC__) || defined(__DARWIN__)
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
+
+#if defined(__GLIBC__) || defined(__DARWIN__) || (__FreeBSD_version >= 1000002)
 #include <xlocale.h>
 #else
 typedef void* locale_t;
