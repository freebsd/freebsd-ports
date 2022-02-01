--- base/process/kill_posix.cc.orig	2021-12-14 11:44:55 UTC
+++ base/process/kill_posix.cc
@@ -162,7 +162,7 @@ void EnsureProcessTerminated(Process process) {
       0, new BackgroundReaper(std::move(process), Seconds(2)));
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void EnsureProcessGetsReaped(Process process) {
   DCHECK(!process.is_current());
 
@@ -173,7 +173,7 @@ void EnsureProcessGetsReaped(Process process) {
   PlatformThread::CreateNonJoinable(
       0, new BackgroundReaper(std::move(process), TimeDelta()));
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #endif  // !defined(OS_APPLE)
 #endif  // !defined(OS_NACL_NONSFI)
