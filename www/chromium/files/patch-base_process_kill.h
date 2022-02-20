--- base/process/kill.h.orig	2022-02-07 13:39:41 UTC
+++ base/process/kill.h
@@ -112,7 +112,7 @@ BASE_EXPORT TerminationStatus GetTerminationStatus(Pro
 BASE_EXPORT TerminationStatus GetKnownDeadTerminationStatus(
     ProcessHandle handle, int* exit_code);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Spawns a thread to wait asynchronously for the child |process| to exit
 // and then reaps it.
 BASE_EXPORT void EnsureProcessGetsReaped(Process process);
