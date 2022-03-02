--- base/allocator/partition_allocator/starscan/stack/stack.cc.orig	2022-02-28 16:54:41 UTC
+++ base/allocator/partition_allocator/starscan/stack/stack.cc
@@ -17,6 +17,10 @@
 #include <pthread.h>
 #endif
 
+#if defined(OS_BSD)
+#include <pthread_np.h>
+#endif
+
 #if defined(LIBC_GLIBC)
 extern "C" void* __libc_stack_end;
 #endif
@@ -48,6 +52,36 @@ void* GetStackTop() {
 
 void* GetStackTop() {
   return pthread_get_stackaddr_np(pthread_self());
+}
+
+#elif defined(OS_OPENBSD)
+
+void* GetStackTop() {
+  stack_t ss;
+  if (pthread_stackseg_np(pthread_self(), &ss) != 0)
+    return nullptr;
+  return reinterpret_cast<uint8_t*>(ss.ss_sp);
+}
+
+#elif defined(OS_FREEBSD)
+
+void* GetStackTop() {
+   pthread_attr_t attr;
+   int error = pthread_attr_init(&attr);
+   if (error) {
+     return nullptr;
+   }
+   error = pthread_attr_get_np(pthread_self(), &attr);
+   if (!error) {
+     void* base;
+     size_t size;
+     error = pthread_attr_getstack(&attr, &base, &size);
+     PA_CHECK(!error);
+     pthread_attr_destroy(&attr);
+     return reinterpret_cast<uint8_t*>(base) + size;
+   }
+  pthread_attr_destroy(&attr);
+  return nullptr;
 }
 
 #elif BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
