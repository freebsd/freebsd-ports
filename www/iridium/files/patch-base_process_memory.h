--- base/process/memory.h.orig	2017-07-25 21:04:48.000000000 +0200
+++ base/process/memory.h	2017-07-29 01:01:15.601297000 +0200
@@ -32,7 +32,7 @@
 // Crash reporting classifies such crashes as OOM.
 BASE_EXPORT void TerminateBecauseOutOfMemory(size_t size);
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
 BASE_EXPORT extern size_t g_oom_size;
 
 // The maximum allowed value for the OOM score.
