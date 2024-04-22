--- base/profiler/module_cache.cc.orig	2024-02-04 14:46:08 UTC
+++ base/profiler/module_cache.cc
@@ -37,7 +37,7 @@ std::string TransformModuleIDToSymbolServerFormat(Stri
   // Android and Linux Chrome builds use the "breakpad" format to index their
   // build id, so we transform the build id for these platforms. All other
   // platforms keep their symbols indexed by the original build ID.
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux ELF module IDs are 160bit integers, which we need to mangle
   // down to 128bit integers to match the id that Breakpad outputs.
   // Example on version '66.0.3359.170' x64:
