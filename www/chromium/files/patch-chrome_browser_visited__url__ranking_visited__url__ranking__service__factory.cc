--- chrome/browser/visited_url_ranking/visited_url_ranking_service_factory.cc.orig	2024-07-30 11:12:21 UTC
+++ chrome/browser/visited_url_ranking/visited_url_ranking_service_factory.cc
@@ -39,7 +39,7 @@
 #include "components/visited_url_ranking/public/visited_url_ranking_service.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/visited_url_ranking/desktop_tab_model_url_visit_data_fetcher.h"
 #elif BUILDFLAG(IS_ANDROID)
 #include "chrome/browser/visited_url_ranking/android_tab_model_url_visit_data_fetcher.h"
@@ -99,7 +99,7 @@ VisitedURLRankingServiceFactory::BuildServiceInstanceF
 
   std::map<Fetcher, std::unique_ptr<URLVisitDataFetcher>> data_fetchers;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   data_fetchers.emplace(
       Fetcher::kTabModel,
       std::make_unique<visited_url_ranking::DesktopTabModelURLVisitDataFetcher>(
