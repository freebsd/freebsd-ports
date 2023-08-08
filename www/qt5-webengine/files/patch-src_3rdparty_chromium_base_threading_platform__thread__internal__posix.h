--- src/3rdparty/chromium/base/threading/platform_thread_internal_posix.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/base/threading/platform_thread_internal_posix.h
@@ -47,13 +47,13 @@ Optional<ThreadPriority> GetCurrentThreadPriorityForPl
 // of CanIncreaseThreadPriority().
 Optional<ThreadPriority> GetCurrentThreadPriorityForPlatform();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Current thread id is cached in thread local storage for performance reasons.
 // In some rare cases it's important to clear that cache explicitly (e.g. after
 // going through clone() syscall which does not call pthread_atfork()
 // handlers).
 BASE_EXPORT void ClearTidCache();
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 }  // namespace internal
 
