--- src/3rdparty/chromium/base/process/kill_posix.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/process/kill_posix.cc
@@ -158,7 +158,7 @@ void EnsureProcessTerminated(Process process) {
       0, new BackgroundReaper(std::move(process), Seconds(2)));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void EnsureProcessGetsReaped(Process process) {
   DCHECK(!process.is_current());
 
