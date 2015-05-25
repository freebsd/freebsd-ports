--- base/process/memory.cc.orig	2015-05-21 15:20:26.547966000 -0400
+++ base/process/memory.cc	2015-05-21 15:24:31.421919000 -0400
@@ -45,4 +45,36 @@
 
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
