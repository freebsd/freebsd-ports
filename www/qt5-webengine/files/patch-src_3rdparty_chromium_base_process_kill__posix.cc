--- src/3rdparty/chromium/base/process/kill_posix.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/process/kill_posix.cc
@@ -167,7 +167,7 @@ void EnsureProcessTerminated(Process process) {
       0, new BackgroundReaper(std::move(process), TimeDelta::FromSeconds(2)));
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void EnsureProcessGetsReaped(Process process) {
   DCHECK(!process.is_current());
 
