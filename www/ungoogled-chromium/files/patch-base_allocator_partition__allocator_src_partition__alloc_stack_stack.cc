--- base/allocator/partition_allocator/src/partition_alloc/stack/stack.cc.orig	2026-11-17 11:49:09 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/stack/stack.cc
@@ -19,6 +19,10 @@
 #include <pthread.h>
 #endif
 
+#if PA_BUILDFLAG(IS_BSD)
+#include <pthread_np.h>
+#endif
+
 #if PA_BUILDFLAG(PA_LIBC_GLIBC)
 extern "C" void* __libc_stack_end;
 #endif
@@ -49,6 +53,36 @@ uintptr_t GetStackTop() {
 
 uintptr_t GetStackTop() {
   return reinterpret_cast<uintptr_t>(pthread_get_stackaddr_np(pthread_self()));
+}
+
+#elif PA_BUILDFLAG(IS_OPENBSD)
+
+uintptr_t GetStackTop() {
+  stack_t ss;
+  if (pthread_stackseg_np(pthread_self(), &ss) != 0)
+    return 0;
+  return reinterpret_cast<uintptr_t>(ss.ss_sp);
+}
+
+#elif PA_BUILDFLAG(IS_FREEBSD)
+
+uintptr_t GetStackTop() {
+   pthread_attr_t attr;
+   int error = pthread_attr_init(&attr);
+   if (error) {
+     return 0;
+   }
+   error = pthread_attr_get_np(pthread_self(), &attr);
+   if (!error) {
+     void* base;
+     size_t size;
+     error = pthread_attr_getstack(&attr, &base, &size);
+     PA_CHECK(!error);
+     pthread_attr_destroy(&attr);
+     return reinterpret_cast<uintptr_t>(base) + size;
+   }
+  pthread_attr_destroy(&attr);
+  return 0;
 }
 
 #elif PA_BUILDFLAG(IS_POSIX) || PA_BUILDFLAG(IS_FUCHSIA)
