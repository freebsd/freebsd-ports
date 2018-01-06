--- src/3rdparty/chromium/base/process/memory.h.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/process/memory.h
@@ -32,7 +32,7 @@ BASE_EXPORT void EnableTerminationOnOutO
 // Crash reporting classifies such crashes as OOM.
 BASE_EXPORT void TerminateBecauseOutOfMemory(size_t size);
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_ANDROID)
 BASE_EXPORT extern size_t g_oom_size;
 
 // The maximum allowed value for the OOM score.
