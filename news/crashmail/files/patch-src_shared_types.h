--- src/shared/types.h.orig	Wed May 16 00:39:05 2001
+++ src/shared/types.h	Tue Jan 21 17:59:12 2003
@@ -2,8 +2,12 @@
 #define SHARED_TYPES_H
 
 #ifdef PLATFORM_LINUX
-#define NO_TYPEDEF_ULONG
 #define NO_TYPEDEF_USHORT
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#else
+#define NO_TYPEDEF_ULONG
+#endif
 #endif
 
 #ifndef NO_TYPEDEF_ULONG
