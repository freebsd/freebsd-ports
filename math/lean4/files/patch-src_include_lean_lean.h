--- src/include/lean/lean.h.orig	2026-07-22 17:50:04 UTC
+++ src/include/lean/lean.h
@@ -17,6 +17,10 @@ Author: Leonardo de Moura
 #include <lean/mimalloc.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
+
 #ifdef __cplusplus
 #include <atomic>
 #include <stdlib.h>
@@ -484,7 +488,15 @@ __attribute__((nothrow))
 // `__attribute__((nothrow))` to be present or `noexcept`.
 __attribute__((nothrow))
 #endif
+#if !defined(__FreeBSD__) || __FreeBSD_version < 1500000
 void free_sized(void* ptr, size_t);
+#else
+#  ifdef __cplusplus
+void free_sized(void* ptr, size_t) throw();
+#  else
+void free_sized(void* ptr, size_t);
+#  endif
+#endif
 #endif
 
 static inline void lean_free_small_object(lean_object * o) {
