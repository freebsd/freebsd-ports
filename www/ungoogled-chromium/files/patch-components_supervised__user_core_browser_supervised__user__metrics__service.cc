--- components/supervised_user/core/browser/supervised_user_metrics_service.cc.orig	2024-07-31 14:19:23 UTC
+++ components/supervised_user/core/browser/supervised_user_metrics_service.cc
@@ -47,7 +47,7 @@ SupervisedUserMetricsService::SupervisedUserMetricsSer
       extensions_metrics_delegate_(std::move(extensions_metrics_delegate)) {
   DCHECK(pref_service_);
   DCHECK(url_filter_);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CHECK(extensions_metrics_delegate_)
       << "Extensions metrics delegate must exist on Win/Linux/Mac";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
