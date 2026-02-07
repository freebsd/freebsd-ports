--- src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.cc
@@ -7,7 +7,7 @@ SamplingProfilerThreadToken GetSamplingProfilerCurrent
 namespace base {
 
 SamplingProfilerThreadToken GetSamplingProfilerCurrentThreadToken() {
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return {PlatformThread::CurrentId(), pthread_self()};
 #else
   return {PlatformThread::CurrentId()};
