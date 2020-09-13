--- perf/ipsec_perf.c.orig	2020-07-30 14:06:18 UTC
+++ perf/ipsec_perf.c
@@ -32,8 +32,11 @@
 #include <inttypes.h>
 #include <string.h>
 #include <errno.h>
+#if defined (__linux__) || defined (__FreeBSD__)
+#include <stdlib.h>
+#else
 #include <malloc.h> /* memalign() or _aligned_malloc()/aligned_free() */
-
+#endif
 #ifdef _WIN32
 #include <windows.h>
 #include <process.h>
