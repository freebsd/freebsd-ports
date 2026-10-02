--- third_party/partition_alloc/src/partition_alloc/stack/stack.cc.orig	2026-09-13 16:45:48 UTC
+++ third_party/partition_alloc/src/partition_alloc/stack/stack.cc
@@ -17,7 +17,10 @@
 #include <windows.h>
 #else
 #include <pthread.h>
+#if PA_BUILDFLAG(IS_FREEBSD)
+#include <pthread_np.h>  // for pthread_attr_get_np
 #endif
+#endif
 
 #if PA_BUILDFLAG(PA_LIBC_GLIBC)
 extern "C" void* __libc_stack_end;
@@ -49,6 +52,22 @@ void* GetStackTop() {
 
 void* GetStackTop() {
   return pthread_get_stackaddr_np(pthread_self());
+}
+
+#elif PA_BUILDFLAG(IS_FREEBSD)
+
+void* GetStackTop() {
+  pthread_attr_t attr;
+  int error = pthread_attr_get_np(pthread_self(), &attr);
+  if (!error) {
+    void* base;
+    size_t size;
+    error = pthread_attr_getstack(&attr, &base, &size);
+    PA_CHECK(!error);
+    pthread_attr_destroy(&attr);
+    return PA_UNSAFE_TODO(reinterpret_cast<uint8_t*>(base) + size);
+  }
+  return nullptr;
 }
 
 #elif PA_BUILDFLAG(IS_POSIX) || PA_BUILDFLAG(IS_FUCHSIA)
