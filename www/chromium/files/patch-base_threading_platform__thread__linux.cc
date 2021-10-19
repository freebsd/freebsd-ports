--- base/threading/platform_thread_linux.cc.orig	2021-10-01 01:36:37 UTC
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
@@ -132,7 +134,7 @@ int sched_setattr(pid_t pid,
 #endif  // !defined(OS_NACL) && !defined(OS_AIX)
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
 const FilePath::CharType kCgroupDirectory[] =
     FILE_PATH_LITERAL("/sys/fs/cgroup");
 
@@ -300,7 +302,7 @@ const ThreadPriorityToNiceValuePair kThreadPriorityToN
 
 absl::optional<bool> CanIncreaseCurrentThreadPriorityForPlatform(
     ThreadPriority priority) {
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
   // A non-zero soft-limit on RLIMIT_RTPRIO is required to be allowed to invoke
   // pthread_setschedparam in SetCurrentThreadPriorityForPlatform().
   struct rlimit rlim;
@@ -313,7 +315,7 @@ absl::optional<bool> CanIncreaseCurrentThreadPriorityF
 }
 
 bool SetCurrentThreadPriorityForPlatform(ThreadPriority priority) {
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
   // For legacy schedtune interface
   SetThreadCgroupsForThreadPriority(PlatformThread::CurrentId(), priority);
 
@@ -350,7 +352,7 @@ absl::optional<ThreadPriority> GetCurrentThreadPriorit
 void PlatformThread::SetName(const std::string& name) {
   ThreadIdNameManager::GetInstance()->SetName(name);
 
-#if !defined(OS_NACL) && !defined(OS_AIX)
+#if !defined(OS_NACL) && !defined(OS_AIX) && !defined(OS_BSD)
   // On linux we can get the thread names to show up in the debugger by setting
   // the process name for the LWP.  We don't want to do this for the main
   // thread because that would rename the process, causing tools like killall
@@ -380,8 +382,10 @@ void PlatformThread::SetThreadPriority(ProcessId proce
   // priority.
   CHECK_NE(thread_id, process_id);
 
+#if !defined(OS_BSD)
   // For legacy schedtune interface
   SetThreadCgroupsForThreadPriority(thread_id, priority);
+#endif
 
 #if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
   // For upstream uclamp interface. We try both legacy (schedtune, as done
@@ -438,7 +442,9 @@ void InitThreading() {}
 void TerminateOnThread() {}
 
 size_t GetDefaultThreadStackSize(const pthread_attr_t& attributes) {
-#if !defined(THREAD_SANITIZER)
+#if defined(OS_BSD)
+  return (1 << 23);
+#elif !defined(THREAD_SANITIZER)
   return 0;
 #else
   // ThreadSanitizer bloats the stack heavily. Evidence has been that the
