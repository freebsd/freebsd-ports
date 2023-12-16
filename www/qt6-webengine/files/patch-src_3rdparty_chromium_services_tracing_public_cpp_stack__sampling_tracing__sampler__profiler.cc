--- src/3rdparty/chromium/services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc.orig	2023-08-16 19:50:41 UTC
+++ src/3rdparty/chromium/services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc
@@ -39,7 +39,7 @@
 #include "third_party/perfetto/protos/perfetto/trace/track_event/process_descriptor.pbzero.h"
 #include "third_party/perfetto/protos/perfetto/trace/track_event/thread_descriptor.pbzero.h"
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 #include "base/profiler/thread_delegate_posix.h"
 #define INITIALIZE_THREAD_DELEGATE_POSIX 1
 #else  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_APPLE)
