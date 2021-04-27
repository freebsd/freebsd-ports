--- base/threading/platform_thread_posix.cc.orig	2021-04-14 18:40:48 UTC
+++ base/threading/platform_thread_posix.cc
@@ -32,6 +32,10 @@
 #include <sys/syscall.h>
 #endif
 
+#if defined(OS_BSD)
+#include <pthread_np.h>
+#endif
+
 #if defined(OS_FUCHSIA)
 #include <zircon/process.h>
 #else
@@ -141,7 +145,7 @@ bool CreateThread(size_t stack_size,
   return success;
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // Store the thread ids in local storage since calling the SWI can be
 // expensive and PlatformThread::CurrentId is used liberally. Clear
@@ -159,11 +163,11 @@ class InitAtFork {
   InitAtFork() { pthread_atfork(nullptr, nullptr, internal::ClearTidCache); }
 };
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 }  // namespace
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 namespace internal {
 
@@ -173,7 +177,7 @@ void ClearTidCache() {
 
 }  // namespace internal
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // static
 PlatformThreadId PlatformThread::CurrentId() {
@@ -181,6 +185,8 @@ PlatformThreadId PlatformThread::CurrentId() {
   // into the kernel.
 #if defined(OS_APPLE)
   return pthread_mach_thread_np(pthread_self());
+#elif defined(OS_BSD)
+  return pthread_getthreadid_np();
 #elif defined(OS_LINUX) || defined(OS_CHROMEOS)
   static NoDestructor<InitAtFork> init_at_fork;
   if (g_thread_id == -1) {
