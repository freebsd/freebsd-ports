--- base/profiler/sampling_profiler_thread_token.cc.orig	2020-02-07 10:24:19 UTC
+++ base/profiler/sampling_profiler_thread_token.cc
@@ -7,7 +7,7 @@
 namespace base {
 
 SamplingProfilerThreadToken GetSamplingProfilerCurrentThreadToken() {
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   return {PlatformThread::CurrentId(), pthread_self()};
 #else
   return {PlatformThread::CurrentId()};
