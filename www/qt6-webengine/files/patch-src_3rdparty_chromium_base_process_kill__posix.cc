--- src/3rdparty/chromium/base/process/kill_posix.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/process/kill_posix.cc
@@ -161,7 +161,7 @@ void EnsureProcessTerminated(Process process) {
       0, new BackgroundReaper(std::move(process), Seconds(2)));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void EnsureProcessGetsReaped(Process process) {
   DCHECK(!process.is_current());
 
