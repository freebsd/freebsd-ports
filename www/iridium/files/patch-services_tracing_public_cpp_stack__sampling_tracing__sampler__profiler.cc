--- services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc.orig	2020-03-17 10:16:22 UTC
+++ services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc
@@ -362,7 +362,7 @@ TracingSamplerProfiler::TracingProfileBuilder::GetCall
     }
 #endif
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
     // Linux ELF module IDs are 160bit integers, which we need to mangle
     // down to 128bit integers to match the id that Breakpad outputs.
     // Example on version '66.0.3359.170' x64:
