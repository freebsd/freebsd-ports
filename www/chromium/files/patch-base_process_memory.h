--- base/process/memory.h.orig	2016-08-03 22:02:10.000000000 +0300
+++ base/process/memory.h	2016-09-11 01:10:36.394804000 +0300
@@ -32,7 +32,7 @@
 // Crash reporting classifies such crashes as OOM.
 BASE_EXPORT void TerminateBecauseOutOfMemory(size_t size);
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_ANDROID)
 BASE_EXPORT extern size_t g_oom_size;
 
 // The maximum allowed value for the OOM score.
