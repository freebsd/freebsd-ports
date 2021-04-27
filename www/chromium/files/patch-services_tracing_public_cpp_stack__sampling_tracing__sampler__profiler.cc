--- services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc.orig	2021-04-14 18:41:08 UTC
+++ services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc
@@ -625,7 +625,7 @@ void TracingSamplerProfiler::TracingProfileBuilder::Sa
 
 // static
 void TracingSamplerProfiler::MangleModuleIDIfNeeded(std::string* module_id) {
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Linux ELF module IDs are 160bit integers, which we need to mangle
   // down to 128bit integers to match the id that Breakpad outputs.
   // Example on version '66.0.3359.170' x64:
