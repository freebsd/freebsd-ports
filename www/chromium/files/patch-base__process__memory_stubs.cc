--- base/process/memory_stubs.cc.orig	2016-01-21 20:31:40.145997166 +0100
+++ base/process/memory_stubs.cc	2016-01-21 20:34:18.367986479 +0100
@@ -26,6 +26,8 @@
 // their respective stdlib function since those functions will return null on a
 // failure to allocate.
 
+#if !defined(OS_FREEBSD)
+// FreeBSD brings it's own implementation in memory.cc -- cmt
 bool UncheckedMalloc(size_t size, void** result) {
   *result = malloc(size);
   return *result != nullptr;
@@ -35,5 +37,6 @@
   *result = calloc(num_items, size);
   return *result != nullptr;
 }
+#endif
 
 }  // namespace base
