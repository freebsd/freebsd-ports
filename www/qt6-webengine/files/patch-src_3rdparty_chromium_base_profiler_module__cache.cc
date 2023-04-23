--- src/3rdparty/chromium/base/profiler/module_cache.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/base/profiler/module_cache.cc
@@ -34,7 +34,7 @@ std::string TransformModuleIDToBreakpadFormat(StringPi
 
 std::string TransformModuleIDToBreakpadFormat(StringPiece module_id) {
   std::string mangled_id(module_id);
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Linux ELF module IDs are 160bit integers, which we need to mangle
   // down to 128bit integers to match the id that Breakpad outputs.
   // Example on version '66.0.3359.170' x64:
