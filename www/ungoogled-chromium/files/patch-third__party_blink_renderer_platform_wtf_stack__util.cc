--- third_party/blink/renderer/platform/wtf/stack_util.cc.orig	2025-12-06 13:30:52 UTC
+++ third_party/blink/renderer/platform/wtf/stack_util.cc
@@ -22,6 +22,11 @@ extern "C" void* __libc_stack_end;  // NOLINT
 #include <sanitizer/asan_interface.h>
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include <sys/signal.h>
+#include <pthread_np.h>
+#endif
+
 namespace blink {
 
 size_t GetUnderestimatedStackSize() {
@@ -66,6 +71,8 @@ size_t GetUnderestimatedStackSize() {
   //    low as 512k.
   //
   return 512 * 1024;
+#elif BUILDFLAG(IS_OPENBSD)
+  return 512 * 1024;
 #elif BUILDFLAG(IS_APPLE)
   // pthread_get_stacksize_np() returns too low a value for the main thread on
   // OSX 10.9,
@@ -156,6 +163,13 @@ void* GetStackStartImpl() {
   ::GetCurrentThreadStackLimits(&lowLimit, &highLimit);
   return reinterpret_cast<void*>(highLimit);
 #endif
+#elif BUILDFLAG(IS_OPENBSD)
+  stack_t ss;
+  void *base;
+  int error = pthread_stackseg_np(pthread_self(), &ss);
+  CHECK(!error);
+  base = (void*)((size_t) ss.ss_sp - ss.ss_size);
+  return reinterpret_cast<uint8_t*>(base) + ss.ss_size;
 #else
 #error Unsupported getStackStart on this platform.
 #endif
