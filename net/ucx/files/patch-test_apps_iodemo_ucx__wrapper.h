--- test/apps/iodemo/ucx_wrapper.h.orig	2026-02-04 09:52:46 UTC
+++ test/apps/iodemo/ucx_wrapper.h
@@ -22,7 +22,11 @@
 #include <string>
 #include <vector>
 #include <queue>
+#if defined(__linux__)
 #include <sys/epoll.h>
+#else
+/* FreeBSD: no epoll; iodemo must build without epoll support */
+#endif
 
 #define MAX_LOG_PREFIX_SIZE   64
 
