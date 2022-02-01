--- base/threading/platform_thread_internal_posix.h.orig	2021-12-31 00:57:18 UTC
+++ base/threading/platform_thread_internal_posix.h
@@ -46,13 +46,13 @@ bool SetCurrentThreadPriorityForPlatform(ThreadPriorit
 // of CanIncreaseThreadPriority().
 absl::optional<ThreadPriority> GetCurrentThreadPriorityForPlatform();
 
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
 
