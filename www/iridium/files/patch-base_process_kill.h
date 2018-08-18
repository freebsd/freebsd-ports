--- base/process/kill.h.orig	2018-07-19 22:11:43.638992000 +0200
+++ base/process/kill.h	2018-07-19 22:12:06.613065000 +0200
@@ -111,7 +111,7 @@
 BASE_EXPORT TerminationStatus GetKnownDeadTerminationStatus(
     ProcessHandle handle, int* exit_code);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Spawns a thread to wait asynchronously for the child |process| to exit
 // and then reaps it.
 BASE_EXPORT void EnsureProcessGetsReaped(Process process);
