Use the definition in memory.cc instead.
--- src/3rdparty/chromium/base/process/memory_stubs.cc.orig	2017-04-19 16:40:17 UTC
+++ src/3rdparty/chromium/base/process/memory_stubs.cc
@@ -32,9 +32,11 @@ bool UncheckedMalloc(size_t size, void**
   return *result != nullptr;
 }
 
+#if !defined(OS_BSD)
 bool UncheckedCalloc(size_t num_items, size_t size, void** result) {
   *result = calloc(num_items, size);
   return *result != nullptr;
 }
+#endif
 
 }  // namespace base
