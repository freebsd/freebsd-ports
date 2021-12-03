--- cargo-crates/jemalloc-sys-0.3.2/jemalloc/include/jemalloc/internal/jemalloc_internal_decls.h.orig	2018-12-12 14:11:23 UTC
+++ cargo-crates/jemalloc-sys-0.3.2/jemalloc/include/jemalloc/internal/jemalloc_internal_decls.h
@@ -1,5 +1,10 @@
 #ifndef JEMALLOC_INTERNAL_DECLS_H
 #define JEMALLOC_INTERNAL_DECLS_H
+#include <sys/param.h>
+#if __FreeBSD_version >= 1400042
+#define _WITH_CPU_SET_T
+# include <sched.h>
+#endif
 
 #include <math.h>
 #ifdef _WIN32
