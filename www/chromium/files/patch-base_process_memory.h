--- base/process/memory.h.orig	2021-07-19 18:45:05 UTC
+++ base/process/memory.h
@@ -32,7 +32,7 @@ BASE_EXPORT void TerminateBecauseOutOfMemory(size_t si
 // TODO: this can be removed when Breakpad is no longer supported.
 BASE_EXPORT extern size_t g_oom_size;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_AIX)
 // The maximum allowed value for the OOM score.
 const int kMaxOomScore = 1000;
