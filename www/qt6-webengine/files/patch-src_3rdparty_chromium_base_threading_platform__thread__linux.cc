--- src/3rdparty/chromium/base/threading/platform_thread_linux.cc.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/base/threading/platform_thread_linux.cc
@@ -30,7 +30,9 @@
 
 #if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX)
 #include <pthread.h>
+#if !BUILDFLAG(IS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/resource.h>
 #include <sys/time.h>
 #include <sys/types.h>
@@ -139,7 +141,7 @@ long sched_setattr(pid_t pid,
 #endif  // !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX)
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 const FilePath::CharType kCgroupDirectory[] =
     FILE_PATH_LITERAL("/sys/fs/cgroup");
 
@@ -313,7 +315,7 @@ void SetThreadCgroupsForThreadType(PlatformThreadId th
 namespace internal {
 
 namespace {
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 const struct sched_param kRealTimePrio = {8};
 #endif
 }  // namespace
@@ -340,7 +342,7 @@ const ThreadTypeToNiceValuePair kThreadTypeToNiceValue
 };
 
 bool CanSetThreadTypeToRealtimeAudio() {
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
   // A non-zero soft-limit on RLIMIT_RTPRIO is required to be allowed to invoke
   // pthread_setschedparam in SetCurrentThreadTypeForPlatform().
   struct rlimit rlim;
@@ -352,7 +354,7 @@ bool CanSetThreadTypeToRealtimeAudio() {
 
 bool SetCurrentThreadTypeForPlatform(ThreadType thread_type,
                                      MessagePumpType pump_type_hint) {
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
   const PlatformThreadId tid = PlatformThread::CurrentId();
 
   if (g_thread_type_delegate &&
@@ -378,7 +380,7 @@ bool SetCurrentThreadTypeForPlatform(ThreadType thread
 
 absl::optional<ThreadPriorityForTest>
 GetCurrentThreadPriorityForPlatformForTest() {
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
   int maybe_sched_rr = 0;
   struct sched_param maybe_realtime_prio = {0};
   if (pthread_getschedparam(pthread_self(), &maybe_sched_rr,
@@ -397,7 +399,7 @@ GetCurrentThreadPriorityForPlatformForTest() {
 void PlatformThread::SetName(const std::string& name) {
   ThreadIdNameManager::GetInstance()->SetName(name);
 
-#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX) && !BUILDFLAG(IS_BSD)
   // On linux we can get the thread names to show up in the debugger by setting
   // the process name for the LWP.  We don't want to do this for the main
   // thread because that would rename the process, causing tools like killall
@@ -417,7 +419,7 @@ void PlatformThread::SetName(const std::string& name) 
 #endif  //  !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX)
 }
 
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 // static
 void PlatformThread::SetThreadTypeDelegate(ThreadTypeDelegate* delegate) {
   // A component cannot override a delegate set by another component, thus
@@ -428,7 +430,7 @@ void PlatformThread::SetThreadTypeDelegate(ThreadTypeD
 }
 #endif
 
-#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX) && !BUILDFLAG(IS_BSD)
 // static
 void PlatformThread::SetThreadType(ProcessId process_id,
                                    PlatformThreadId thread_id,
