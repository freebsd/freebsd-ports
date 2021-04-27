--- base/process/memory.h.orig	2021-04-14 18:40:48 UTC
+++ base/process/memory.h
@@ -31,7 +31,7 @@ BASE_EXPORT void TerminateBecauseOutOfMemory(size_t si
 // TODO: this can be removed when Breakpad is no longer supported.
 BASE_EXPORT extern size_t g_oom_size;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_AIX)
 // The maximum allowed value for the OOM score.
 const int kMaxOomScore = 1000;
