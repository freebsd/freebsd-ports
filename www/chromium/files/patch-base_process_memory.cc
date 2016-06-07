--- base/process/memory.cc.orig	2016-03-25 13:04:44 UTC
+++ base/process/memory.cc
@@ -46,4 +46,36 @@ bool UncheckedCalloc(size_t num_items, s
 
 #endif
 
+#if defined(OS_FREEBSD)
+
+#if defined(USE_TCMALLOC)
+// Used by UncheckedMalloc. If tcmalloc is linked to the executable
+// this will be replaced by a strong symbol that actually implement
+// the semantics and don't call new handler in case the allocation fails.
+extern "C" {
+      
+__attribute__((weak, visibility("default")))
+void* tc_malloc_skip_new_handler_weak(size_t size);
+
+void* tc_malloc_skip_new_handler_weak(size_t size) {
+  return malloc(size);
+}
+
+}
+#endif
+
+bool UncheckedMalloc(size_t size, void** result) {
+#if defined(MEMORY_TOOL_REPLACES_ALLOCATOR) || \ 
+    (!defined(LIBC_GLIBC) && !defined(USE_TCMALLOC))
+  *result = malloc(size);
+#elif defined(LIBC_GLIBC) && !defined(USE_TCMALLOC)
+  *result = __libc_malloc(size);
+#elif defined(USE_TCMALLOC)
+  *result = tc_malloc_skip_new_handler_weak(size);
+#endif
+  return *result != NULL;
+}
+
+#endif // defined(OS_FREEBSD)
+
 }  // namespace base
