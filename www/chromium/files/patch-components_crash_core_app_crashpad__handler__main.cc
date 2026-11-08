--- components/crash/core/app/crashpad_handler_main.cc.orig	2026-10-18 13:29:39 UTC
+++ components/crash/core/app/crashpad_handler_main.cc
@@ -13,7 +13,7 @@
 #include "third_party/crashpad/crashpad/handler/handler_main.h"
 #include "third_party/crashpad/crashpad/handler/user_stream_data_source.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "components/stability_report/user_stream_data_source_posix.h"
 #endif
 
@@ -38,7 +38,7 @@ __attribute__((visibility("default"), used)) int Crash
     char* argv[]) {
   crashpad::UserStreamDataSources user_stream_data_sources;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   user_stream_data_sources.push_back(
       std::make_unique<stability_report::UserStreamDataSourcePosix>());
 #endif
