--- ./xbmc/lib/libXBMS/ccincludes.h.orig	2010-04-18 23:05:41.000000000 +0200
+++ ./xbmc/lib/libXBMS/ccincludes.h	2010-12-01 12:17:34.244845160 +0100
@@ -58,6 +58,10 @@
 #define snprintf _snprintf
 #endif /* _XBOX */
 
+#if defined(__FreeBSD__)
+#include <netinet/in.h>
+#endif
+
 //extern int errno;
 
 #ifndef PATH_MAX
