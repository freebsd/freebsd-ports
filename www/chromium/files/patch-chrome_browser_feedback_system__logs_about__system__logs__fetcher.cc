--- chrome/browser/feedback/system_logs/about_system_logs_fetcher.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/feedback/system_logs/about_system_logs_fetcher.cc
@@ -35,7 +35,7 @@
 #include "chrome/browser/ash/system_logs/ui_hierarchy_log_source.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/feedback/system_logs/log_sources/ozone_platform_state_dump_source.h"
 #endif
 
@@ -78,7 +78,7 @@ SystemLogsFetcher* BuildAboutSystemLogsFetcher(content
   fetcher->AddSource(std::make_unique<KeyboardInfoLogSource>());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   fetcher->AddSource(std::make_unique<OzonePlatformStateDumpSource>());
 #endif  // BUILDFLAG(IS_LINUX)
 
