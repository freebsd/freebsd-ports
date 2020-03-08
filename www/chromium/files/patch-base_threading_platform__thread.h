--- base/threading/platform_thread.h.orig	2020-03-03 18:52:59 UTC
+++ base/threading/platform_thread.h
@@ -36,6 +36,8 @@ typedef DWORD PlatformThreadId;
 typedef zx_handle_t PlatformThreadId;
 #elif defined(OS_MACOSX)
 typedef mach_port_t PlatformThreadId;
+#elif defined(OS_FREEBSD)
+typedef long PlatformThreadId;
 #elif defined(OS_POSIX)
 typedef pid_t PlatformThreadId;
 #endif
@@ -221,7 +223,7 @@ class BASE_EXPORT PlatformThread {
 
   static ThreadPriority GetCurrentThreadPriority();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Toggles a specific thread's priority at runtime. This can be used to
   // change the priority of a thread in a different process and will fail
   // if the calling process does not have proper permissions. The
