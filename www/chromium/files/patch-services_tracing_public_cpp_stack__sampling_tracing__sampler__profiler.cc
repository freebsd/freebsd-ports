--- services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc.orig	2021-12-14 11:45:10 UTC
+++ services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc
@@ -622,7 +622,7 @@ void TracingSamplerProfiler::StackProfileWriter::Reset
 
 // static
 void TracingSamplerProfiler::MangleModuleIDIfNeeded(std::string* module_id) {
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Linux ELF module IDs are 160bit integers, which we need to mangle
   // down to 128bit integers to match the id that Breakpad outputs.
   // Example on version '66.0.3359.170' x64:
