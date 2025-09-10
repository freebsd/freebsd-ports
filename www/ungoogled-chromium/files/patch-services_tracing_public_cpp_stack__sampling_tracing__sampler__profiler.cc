--- services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc.orig	2025-09-10 13:22:16 UTC
+++ services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc
@@ -39,7 +39,7 @@
 #include "third_party/perfetto/protos/perfetto/trace/track_event/process_descriptor.pbzero.h"
 #include "third_party/perfetto/protos/perfetto/trace/track_event/thread_descriptor.pbzero.h"
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 #include "base/profiler/thread_delegate_posix.h"
 #define INITIALIZE_THREAD_DELEGATE_POSIX 1
 #else  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE)
@@ -261,7 +261,7 @@ struct FrameDetails {
     ANDROID_ARM64_UNWINDING_SUPPORTED || ANDROID_CFI_UNWINDING_SUPPORTED || \
     (BUILDFLAG(IS_CHROMEOS) &&                                              \
      (defined(ARCH_CPU_X86_64) || defined(ARCH_CPU_ARM64))) ||              \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns whether stack sampling is supported on the current platform.
 bool IsStackSamplingSupported() {
   return base::StackSamplingProfiler::IsSupportedForCurrentPlatform();
@@ -379,7 +379,7 @@ void TracingSamplerProfiler::TracingProfileBuilder::Wr
     thread_descriptor->set_reference_timestamp_us(
         last_timestamp_.since_origin().InMicroseconds());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
     if (base::GetCurrentProcId() !=
         base::trace_event::TraceLog::GetInstance()->process_id()) {
       auto* chrome_thread = track_descriptor->set_chrome_thread();
@@ -651,7 +651,7 @@ bool TracingSamplerProfiler::IsStackUnwindingSupported
     ANDROID_ARM64_UNWINDING_SUPPORTED || ANDROID_CFI_UNWINDING_SUPPORTED || \
     (BUILDFLAG(IS_CHROMEOS) &&                                              \
      (defined(ARCH_CPU_X86_64) || defined(ARCH_CPU_ARM64))) ||              \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return IsStackSamplingSupported();
 #else
   return false;
