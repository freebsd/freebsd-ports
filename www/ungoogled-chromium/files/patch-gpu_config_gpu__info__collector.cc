--- gpu/config/gpu_info_collector.cc.orig	2024-10-01 07:26:23 UTC
+++ gpu/config/gpu_info_collector.cc
@@ -370,7 +370,7 @@ void ReportWebGPUAdapterMetrics(dawn::native::Instance
 void ReportWebGPUSupportMetrics(dawn::native::Instance* instance) {
   static BASE_FEATURE(kCollectWebGPUSupportMetrics,
                       "CollectWebGPUSupportMetrics",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                       base::FEATURE_DISABLED_BY_DEFAULT);
 #else
                       base::FEATURE_ENABLED_BY_DEFAULT);
