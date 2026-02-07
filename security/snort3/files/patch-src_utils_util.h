--- src/utils/util.h.orig	2024-05-27 15:47:21 UTC
+++ src/utils/util.h
@@ -27,6 +27,9 @@
 #if defined(__linux__)
 #include <sys/syscall.h>
 #endif
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/types.h>
+#endif
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <unistd.h>
