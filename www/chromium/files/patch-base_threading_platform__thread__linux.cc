--- base/threading/platform_thread_linux.cc.orig	2022-01-20 10:35:46 UTC
+++ base/threading/platform_thread_linux.cc
@@ -29,7 +29,9 @@
 
 #if !defined(OS_NACL) && !defined(OS_AIX)
 #include <pthread.h>
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/resource.h>
 #include <sys/time.h>
 #include <sys/types.h>
@@ -61,7 +63,7 @@ int g_scheduler_boost_adj;
 int g_scheduler_limit_adj;
 bool g_scheduler_use_latency_tune_adj;
 
-#if !defined(OS_NACL) && !defined(OS_AIX)
+#if !defined(OS_NACL) && !defined(OS_AIX) && !defined(OS_BSD)
 
 // Defined by linux uclamp ABI of sched_setattr().
 const uint32_t kSchedulerUclampMin = 0;
@@ -129,10 +131,10 @@ int sched_setattr(pid_t pid,
                   unsigned int flags) {
   return syscall(__NR_sched_setattr, pid, attr, flags);
 }
-#endif  // !defined(OS_NACL) && !defined(OS_AIX)
+#endif  // !defined(OS_NACL) && !defined(OS_AIX) && !defined(OS_BSD)
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
 const FilePath::CharType kCgroupDirectory[] =
     FILE_PATH_LITERAL("/sys/fs/cgroup");
 
@@ -286,7 +288,7 @@ void SetThreadCgroupsForThreadPriority(PlatformThreadI
 namespace internal {
 
 namespace {
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
 const struct sched_param kRealTimePrio = {8};
 #endif
 }  // namespace
@@ -299,7 +301,7 @@ const ThreadPriorityToNiceValuePair kThreadPriorityToN
 };
 
 bool CanSetThreadPriorityToRealtimeAudio() {
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
   // A non-zero soft-limit on RLIMIT_RTPRIO is required to be allowed to invoke
   // pthread_setschedparam in SetCurrentThreadPriorityForPlatform().
   struct rlimit rlim;
@@ -310,7 +312,7 @@ bool CanSetThreadPriorityToRealtimeAudio() {
 }
 
 bool SetCurrentThreadPriorityForPlatform(ThreadPriority priority) {
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
   // For legacy schedtune interface
   SetThreadCgroupsForThreadPriority(PlatformThread::CurrentId(), priority);
 
@@ -328,7 +330,7 @@ bool SetCurrentThreadPriorityForPlatform(ThreadPriorit
 }
 
 absl::optional<ThreadPriority> GetCurrentThreadPriorityForPlatform() {
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
   int maybe_sched_rr = 0;
   struct sched_param maybe_realtime_prio = {0};
   if (pthread_getschedparam(pthread_self(), &maybe_sched_rr,
@@ -347,7 +349,7 @@ absl::optional<ThreadPriority> GetCurrentThreadPriorit
 void PlatformThread::SetName(const std::string& name) {
   ThreadIdNameManager::GetInstance()->SetName(name);
 
-#if !defined(OS_NACL) && !defined(OS_AIX)
+#if !defined(OS_NACL) && !defined(OS_AIX) && !defined(OS_BSD)
   // On linux we can get the thread names to show up in the debugger by setting
   // the process name for the LWP.  We don't want to do this for the main
   // thread because that would rename the process, causing tools like killall
@@ -364,7 +366,7 @@ void PlatformThread::SetName(const std::string& name) 
   // We expect EPERM failures in sandboxed processes, just ignore those.
   if (err < 0 && errno != EPERM)
     DPLOG(ERROR) << "prctl(PR_SET_NAME)";
-#endif  //  !defined(OS_NACL) && !defined(OS_AIX)
+#endif  //  !defined(OS_NACL) && !defined(OS_AIX) && !defined(OS_BSD)
 }
 
 #if !defined(OS_NACL) && !defined(OS_AIX)
@@ -377,8 +379,10 @@ void PlatformThread::SetThreadPriority(ProcessId proce
   // priority.
   CHECK_NE(thread_id, process_id);
 
+#if !defined(OS_BSD)
   // For legacy schedtune interface
   SetThreadCgroupsForThreadPriority(thread_id, priority);
+#endif
 
 #if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
   // For upstream uclamp interface. We try both legacy (schedtune, as done
@@ -435,7 +439,9 @@ void InitThreading() {}
 void TerminateOnThread() {}
 
 size_t GetDefaultThreadStackSize(const pthread_attr_t& attributes) {
-#if !defined(THREAD_SANITIZER)
+#if defined(OS_BSD)
+  return (1 << 23);
+#elif !defined(THREAD_SANITIZER)
   return 0;
 #else
   // ThreadSanitizer bloats the stack heavily. Evidence has been that the
