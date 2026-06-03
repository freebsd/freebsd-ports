--- mpifileutils/src/common/mfu_compress_bz2_libcircle.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_compress_bz2_libcircle.c
@@ -1,3 +1,20 @@
+#if !defined(__linux__)
+/*
+ * Non-Linux fallback:
+ * The libcircle-based implementation relies on sysinfo(2) / <sys/sysinfo.h>.
+ * FreeBSD doesn't provide that API, so fall back to the portable static path.
+ */
+#include "mfu.h"
+#include "mfu_bz2.h"
+
+int mfu_compress_bz2_libcircle(const char* src, const char* dst, int b_size, ssize_t opts_memory)
+{
+    (void) opts_memory;
+    return mfu_compress_bz2_static(src, dst, b_size);
+}
+
+#else /* __linux__ */
+
 #ifndef _GNU_SOURCE
 #define _GNU_SOURCE
 #endif
@@ -531,3 +548,4 @@ int mfu_compress_bz2_libcircle(const char* src, const 
 
     return rc;
 }
+#endif /* __linux__ */
