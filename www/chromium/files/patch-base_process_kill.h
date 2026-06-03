--- base/process/kill.h.orig	2025-10-30 15:44:36 UTC
+++ base/process/kill.h
@@ -125,7 +125,7 @@ BASE_EXPORT TerminationStatus GetTerminationStatus(Pro
 BASE_EXPORT TerminationStatus
 GetKnownDeadTerminationStatus(ProcessHandle handle, int* exit_code);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Spawns a thread to wait asynchronously for the child |process| to exit
 // and then reaps it.
 BASE_EXPORT void EnsureProcessGetsReaped(Process process);
