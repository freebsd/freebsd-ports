--- base/process/memory.h.orig	2019-03-11 22:00:51 UTC
+++ base/process/memory.h
@@ -32,7 +32,7 @@ BASE_EXPORT void EnableTerminationOnOutOfMemory();
 // Crash reporting classifies such crashes as OOM.
 BASE_EXPORT void TerminateBecauseOutOfMemory(size_t size);
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
 BASE_EXPORT extern size_t g_oom_size;
 
 // The maximum allowed value for the OOM score.
