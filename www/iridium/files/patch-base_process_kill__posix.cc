--- base/process/kill_posix.cc.orig	2026-08-13 16:48:13 UTC
+++ base/process/kill_posix.cc
@@ -169,7 +169,7 @@ void EnsureProcessTerminated(Process process) {
       0, MakeSelfDeleting<BackgroundReaper>(std::move(process), Seconds(2)));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void EnsureProcessGetsReaped(Process process) {
   DCHECK(!process.is_current());
 
