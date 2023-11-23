--- src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.cc.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <pthread.h>
 
 #include "base/profiler/stack_base_address_posix.h"
@@ -18,7 +18,7 @@ SamplingProfilerThreadToken GetSamplingProfilerCurrent
   PlatformThreadId id = PlatformThread::CurrentId();
 #if BUILDFLAG(IS_ANDROID)
   return {id, pthread_self()};
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   absl::optional<uintptr_t> maybe_stack_base =
       GetThreadStackBaseAddress(id, pthread_self());
   return {id, maybe_stack_base};
