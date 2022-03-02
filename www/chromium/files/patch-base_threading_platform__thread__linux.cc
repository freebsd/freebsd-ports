--- base/threading/platform_thread_linux.cc.orig	2022-02-28 16:54:41 UTC
+++ base/threading/platform_thread_linux.cc
@@ -29,7 +29,9 @@
 
 #if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX)
 #include <pthread.h>
+#if !BUILDFLAG(IS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/resource.h>
 #include <sys/time.h>
 #include <sys/types.h>
@@ -132,7 +134,7 @@ int sched_setattr(pid_t pid,
 #endif  // !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX)
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 const FilePath::CharType kCgroupDirectory[] =
     FILE_PATH_LITERAL("/sys/fs/cgroup");
 
@@ -286,7 +288,7 @@ void SetThreadCgroupsForThreadPriority(PlatformThreadI
 namespace internal {
 
 namespace {
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 const struct sched_param kRealTimePrio = {8};
 #endif
 }  // namespace
@@ -299,7 +301,7 @@ const ThreadPriorityToNiceValuePair kThreadPriorityToN
 };
 
 bool CanSetThreadPriorityToRealtimeAudio() {
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
   // A non-zero soft-limit on RLIMIT_RTPRIO is required to be allowed to invoke
   // pthread_setschedparam in SetCurrentThreadPriorityForPlatform().
   struct rlimit rlim;
@@ -310,7 +312,7 @@ bool CanSetThreadPriorityToRealtimeAudio() {
 }
 
 bool SetCurrentThreadPriorityForPlatform(ThreadPriority priority) {
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
   // For legacy schedtune interface
   SetThreadCgroupsForThreadPriority(PlatformThread::CurrentId(), priority);
 
@@ -328,7 +330,7 @@ bool SetCurrentThreadPriorityForPlatform(ThreadPriorit
 }
 
 absl::optional<ThreadPriority> GetCurrentThreadPriorityForPlatform() {
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
   int maybe_sched_rr = 0;
   struct sched_param maybe_realtime_prio = {0};
   if (pthread_getschedparam(pthread_self(), &maybe_sched_rr,
@@ -347,7 +349,7 @@ absl::optional<ThreadPriority> GetCurrentThreadPriorit
 void PlatformThread::SetName(const std::string& name) {
   ThreadIdNameManager::GetInstance()->SetName(name);
 
-#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX) && !BUILDFLAG(IS_BSD)
   // On linux we can get the thread names to show up in the debugger by setting
   // the process name for the LWP.  We don't want to do this for the main
   // thread because that would rename the process, causing tools like killall
@@ -377,8 +379,10 @@ void PlatformThread::SetThreadPriority(ProcessId proce
   // priority.
   CHECK_NE(thread_id, process_id);
 
+#if !BUILDFLAG(IS_BSD)
   // For legacy schedtune interface
   SetThreadCgroupsForThreadPriority(thread_id, priority);
+#endif
 
 #if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
   // For upstream uclamp interface. We try both legacy (schedtune, as done
