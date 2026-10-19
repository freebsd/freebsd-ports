--- components/supervised_user/core/browser/supervised_user_metrics_service.cc.orig	2026-10-18 13:29:39 UTC
+++ components/supervised_user/core/browser/supervised_user_metrics_service.cc
@@ -116,7 +116,7 @@ SupervisedUserMetricsService::SupervisedUserMetricsSer
   DCHECK(pref_service_);
   url_filtering_service_observation_.Observe(&url_filtering_service);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CHECK(extensions_metrics_delegate_)
       << "Extensions metrics delegate must exist on Win/Linux/Mac";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
