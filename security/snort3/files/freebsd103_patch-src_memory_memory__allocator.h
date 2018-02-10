--- src/memory/memory_allocator.h.orig	2018-02-01 22:21:37 UTC
+++ src/memory/memory_allocator.h
@@ -34,4 +34,11 @@ struct MemoryAllocator
 
 } // namespace memory
 
+// Fix for FreeBSD 10.3's broken toolchain
+typedef struct {
+    long long __max_align1 __aligned(_Alignof(long long));
+    long double __max_align2 __aligned(_Alignof(long double));
+} max_align_t;
+
+
 #endif
