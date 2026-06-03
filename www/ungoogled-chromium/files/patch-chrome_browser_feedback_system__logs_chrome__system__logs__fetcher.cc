--- chrome/browser/feedback/system_logs/chrome_system_logs_fetcher.cc.orig	2026-04-15 11:25:12 UTC
+++ chrome/browser/feedback/system_logs/chrome_system_logs_fetcher.cc
@@ -46,7 +46,7 @@
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/feedback/system_logs/log_sources/ozone_platform_state_dump_source.h"
 #endif
 
@@ -103,7 +103,7 @@ SystemLogsFetcher* BuildChromeSystemLogsFetcher(Profil
   fetcher->AddSource(std::make_unique<UiHierarchyLogSource>(scrub_data));
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   fetcher->AddSource(std::make_unique<OzonePlatformStateDumpSource>());
 #endif  // BUILDFLAG(IS_LINUX)
 
