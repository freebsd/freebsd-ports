--- src/common/memrchr.h.orig	2026-09-20 18:34:58 UTC
+++ src/common/memrchr.h
@@ -8,7 +8,9 @@ extern "C" {
 
 // `memrchr` is a GNU extension and may not be declared by system headers even when the symbol exists.
 // Declare it unconditionally; the build system provides a fallback implementation when missing.
+#ifndef memrchr
 void* memrchr(const void* s, int c, size_t n);
+#endif
 
 #ifdef __cplusplus
 }
