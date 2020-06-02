--- services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc.orig	2020-05-13 18:40:33 UTC
+++ services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc
@@ -476,7 +476,7 @@ TracingSamplerProfiler::TracingProfileBuilder::GetCall
 
 // static
 void TracingSamplerProfiler::MangleModuleIDIfNeeded(std::string* module_id) {
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   // Linux ELF module IDs are 160bit integers, which we need to mangle
   // down to 128bit integers to match the id that Breakpad outputs.
   // Example on version '66.0.3359.170' x64:
