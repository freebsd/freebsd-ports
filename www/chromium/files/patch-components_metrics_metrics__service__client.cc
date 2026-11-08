--- components/metrics/metrics_service_client.cc.orig	2026-09-25 15:26:43 UTC
+++ components/metrics/metrics_service_client.cc
@@ -39,7 +39,7 @@ struct LogTrimmingDefaults {
 };
 
 constexpr LogTrimmingDefaults GetLogTrimmingDefaults() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return {
       .initial_log_count_trim_threshold = 20,
       .ongoing_log_count_trim_threshold = 8,
