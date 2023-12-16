--- src/3rdparty/chromium/base/profiler/module_cache.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/base/profiler/module_cache.cc
@@ -37,7 +37,7 @@ std::string TransformModuleIDToSymbolServerFormat(Stri
   // Android and Linux Chrome builds use the "breakpad" format to index their
   // build id, so we transform the build id for these platforms. All other
   // platforms keep their symbols indexed by the original build ID.
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux ELF module IDs are 160bit integers, which we need to mangle
   // down to 128bit integers to match the id that Breakpad outputs.
   // Example on version '66.0.3359.170' x64:
