--- components/supervised_user/core/browser/supervised_user_metrics_service.cc.orig	2026-03-13 06:02:14 UTC
+++ components/supervised_user/core/browser/supervised_user_metrics_service.cc
@@ -104,7 +104,7 @@ SupervisedUserMetricsService::SupervisedUserMetricsSer
     supervised_user_service_observation_.Observe(&supervised_user_service);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CHECK(extensions_metrics_delegate_)
       << "Extensions metrics delegate must exist on Win/Linux/Mac";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
