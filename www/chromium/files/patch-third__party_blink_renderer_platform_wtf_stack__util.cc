--- third_party/blink/renderer/platform/wtf/stack_util.cc.orig	2022-02-07 13:39:41 UTC
+++ third_party/blink/renderer/platform/wtf/stack_util.cc
@@ -18,6 +18,11 @@
 extern "C" void* __libc_stack_end;  // NOLINT
 #endif
 
+#if defined(OS_BSD)
+#include <sys/signal.h>
+#include <pthread_np.h>
+#endif
+
 namespace WTF {
 
 size_t GetUnderestimatedStackSize() {
@@ -62,6 +67,8 @@ size_t GetUnderestimatedStackSize() {
   //    low as 512k.
   //
   return 512 * 1024;
+#elif defined(OS_OPENBSD)
+  return 512 * 1024;
 #elif defined(OS_MAC)
   // pthread_get_stacksize_np() returns too low a value for the main thread on
   // OSX 10.9,
@@ -98,12 +105,18 @@ return Threading::ThreadStackSize();
 
 void* GetStackStart() {
 #if defined(__GLIBC__) || defined(OS_ANDROID) || defined(OS_FREEBSD) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   pthread_attr_t attr;
   int error;
 #if defined(OS_FREEBSD)
   pthread_attr_init(&attr);
   error = pthread_attr_get_np(pthread_self(), &attr);
+#elif defined(OS_OPENBSD)
+  stack_t ss;
+  void *base;
+  error = pthread_stackseg_np(pthread_self(), &ss);
+  base = (void*)((size_t) ss.ss_sp - ss.ss_size);
+  return reinterpret_cast<uint8_t*>(base) + ss.ss_size;
 #else
   error = pthread_getattr_np(pthread_self(), &attr);
 #endif
