--- src/remoted/manager.c	2025-12-16 11:37:43.185027000 -0800
+++ src/remoted/manager.c	2025-12-16 11:38:04.427583000 -0800
@@ -18,7 +18,12 @@
 #include "../os_crypto/sha256/sha256_op.h"
 #include <pthread.h>
 
-#if defined(__FreeBSD__) || defined(__MACH__) || defined(__sun__)
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#define HOST_NAME_MAX MAXHOSTNAMELEN
+#endif
+
+#if defined(__MACH__) || defined(__sun__)
 #define HOST_NAME_MAX 64
 #endif
 
