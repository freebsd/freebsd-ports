--- base/allocator/partition_allocator/starscan/stack/stack.cc.orig	2021-07-28 10:41:10 UTC
+++ base/allocator/partition_allocator/starscan/stack/stack.cc
@@ -17,6 +17,10 @@
 #include <pthread.h>
 #endif
 
+#if defined(OS_FREEBSD)
+#include <pthread_np.h>
+#endif
+
 #if defined(LIBC_GLIBC)
 extern "C" void* __libc_stack_end;
 #endif
@@ -54,7 +58,15 @@ void* GetStackTop() {
 
 void* GetStackTop() {
   pthread_attr_t attr;
+#if defined(OS_FREEBSD)
+  int error = pthread_attr_init(&attr);
+  if (error) {
+    return nullptr;
+  }
+  error = pthread_attr_get_np(pthread_self(), &attr);
+#else
   int error = pthread_getattr_np(pthread_self(), &attr);
+#endif
   if (!error) {
     void* base;
     size_t size;
@@ -71,6 +83,9 @@ void* GetStackTop() {
   // See https://code.google.com/p/nativeclient/issues/detail?id=3431.
   return __libc_stack_end;
 #endif  // defined(LIBC_GLIBC)
+#if defined(OS_FREEBSD)
+  pthread_attr_destroy(&attr);
+#endif
   return nullptr;
 }
 
