--- src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.cc.orig	2020-04-08 09:41:36 UTC
+++ src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.cc
@@ -7,7 +7,7 @@
 namespace base {
 
 SamplingProfilerThreadToken GetSamplingProfilerCurrentThreadToken() {
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   return {PlatformThread::CurrentId(), pthread_self()};
 #else
   return {PlatformThread::CurrentId()};
