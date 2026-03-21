--- src/examples/video-src-fixate.c.orig	2026-03-16 11:54:17 UTC
+++ src/examples/video-src-fixate.c
@@ -18,7 +18,11 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/mman.h>
+#ifdef __linux__
 #include <sys/sysmacros.h>
+#else
+#include <sys/types.h>
+#endif
 #include <assert.h>
 
 #include <spa/param/dict-utils.h>
