--- gpu/config/gpu_info_collector.cc.orig	2024-02-23 21:04:38 UTC
+++ gpu/config/gpu_info_collector.cc
@@ -364,7 +364,7 @@ void ReportWebGPUAdapterMetrics(dawn::native::Instance
 void ReportWebGPUSupportMetrics(dawn::native::Instance* instance) {
   static BASE_FEATURE(kCollectWebGPUSupportMetrics,
                       "CollectWebGPUSupportMetrics",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                       base::FEATURE_DISABLED_BY_DEFAULT);
 #else
                       base::FEATURE_ENABLED_BY_DEFAULT);
