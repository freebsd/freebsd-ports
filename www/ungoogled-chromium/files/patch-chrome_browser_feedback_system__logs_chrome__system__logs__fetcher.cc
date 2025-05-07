--- chrome/browser/feedback/system_logs/chrome_system_logs_fetcher.cc.orig	2025-05-06 12:23:00 UTC
+++ chrome/browser/feedback/system_logs/chrome_system_logs_fetcher.cc
@@ -44,7 +44,7 @@
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/feedback/system_logs/log_sources/ozone_platform_state_dump_source.h"
 #endif
 
@@ -101,7 +101,7 @@ SystemLogsFetcher* BuildChromeSystemLogsFetcher(Profil
   fetcher->AddSource(std::make_unique<UiHierarchyLogSource>(scrub_data));
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   fetcher->AddSource(std::make_unique<OzonePlatformStateDumpSource>());
 #endif  // BUILDFLAG(IS_LINUX)
 
