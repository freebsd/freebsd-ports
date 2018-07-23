--- base/process/kill_posix.cc.orig	2018-07-19 22:11:49.327358000 +0200
+++ base/process/kill_posix.cc	2018-07-19 22:12:22.837132000 +0200
@@ -167,7 +167,7 @@
       0, new BackgroundReaper(std::move(process), TimeDelta::FromSeconds(2)));
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void EnsureProcessGetsReaped(Process process) {
   DCHECK(!process.is_current());
 
