--- base/profiler/sampling_profiler_thread_token.cc.orig	2026-10-18 13:29:39 UTC
+++ base/profiler/sampling_profiler_thread_token.cc
@@ -7,7 +7,7 @@
 #include "base/check_op.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <pthread.h>
 
 #include "base/profiler/stack_base_address_posix.h"
@@ -30,7 +30,7 @@ SamplingProfilerThreadToken SamplingProfilerThreadToke
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_APPLE)
   const auto& [target_id, target_pthread_id] = *this;
   return {target_id, target_pthread_id};
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const auto& [target_id, target_stack_base_address] = *this;
   return {target_id, target_stack_base_address};
 #elif BUILDFLAG(IS_WIN)
@@ -49,7 +49,7 @@ SamplingProfilerThreadToken GetSamplingProfilerCurrent
   DCHECK_NE(id, kInvalidThreadId);
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_APPLE)
   return {id, pthread_self()};
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::optional<uintptr_t> maybe_stack_base =
       GetThreadStackBaseAddress(id, pthread_self());
   return {id, maybe_stack_base};
