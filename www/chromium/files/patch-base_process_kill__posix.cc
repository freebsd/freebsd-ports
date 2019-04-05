--- base/process/kill_posix.cc.orig	2019-03-11 22:00:51 UTC
+++ base/process/kill_posix.cc
@@ -168,7 +168,7 @@ void EnsureProcessTerminated(Process process) {
       0, new BackgroundReaper(std::move(process), TimeDelta::FromSeconds(2)));
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void EnsureProcessGetsReaped(Process process) {
   DCHECK(!process.is_current());
 
