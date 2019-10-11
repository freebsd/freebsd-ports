--- lib/flb_libco/aarch64.c.orig	2019-08-21 20:51:37 UTC
+++ lib/flb_libco/aarch64.c
@@ -12,7 +12,11 @@
 #include <string.h>
 #include <stdint.h>
 
-#ifndef IOS
+#if defined(IOS)
+#elif defined(__FreeBSD__)
+#include <malloc_np.h>
+#define HAVE_POSIX_MEMALIGN 1
+#else
 #include <malloc.h>
 #endif
 
