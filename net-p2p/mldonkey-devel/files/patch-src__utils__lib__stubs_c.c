--- src/utils/lib/stubs_c.c.orig	Wed Jan  4 12:23:37 2006
+++ src/utils/lib/stubs_c.c	Mon Jan 16 14:14:38 2006
@@ -28,6 +28,11 @@
 #include <inttypes.h>
 #endif
 
+/* For proper FreeBSD version identification */
+#if defined(HAVE_SYS_PARAM_H)
+#include <sys/param.h>
+#endif
+
 #define lseek XXXXXXXXX
 #define read XXXXXXXXX
 #define ftruncate XXXXXXXXX
@@ -683,7 +688,7 @@
 
 #define NETDB_BUFFER_SIZE 10000
 
-#ifdef _WIN32
+#if defined(_WIN32) || ( defined(__FreeBSD_version) && ( ((__FreeBSD_version >= 504102) && (__FreeBSD_version < 600000)) || (__FreeBSD_version >= 600029) ) )
 #define GETHOSTBYADDR_IS_REENTRANT 1
 #define GETHOSTBYNAME_IS_REENTRANT 1
 #endif
