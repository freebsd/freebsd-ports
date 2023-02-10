--- src/3rdparty/chromium/base/process/kill.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/process/kill.h
@@ -113,7 +113,7 @@ BASE_EXPORT TerminationStatus GetKnownDeadTerminationS
 BASE_EXPORT TerminationStatus GetKnownDeadTerminationStatus(
     ProcessHandle handle, int* exit_code);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Spawns a thread to wait asynchronously for the child |process| to exit
 // and then reaps it.
 BASE_EXPORT void EnsureProcessGetsReaped(Process process);
