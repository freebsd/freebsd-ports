--- src/3rdparty/chromium/gpu/config/gpu_info_collector.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/gpu/config/gpu_info_collector.cc
@@ -361,7 +361,7 @@ void ReportWebGPUSupportMetrics(dawn::native::Instance
 }
 
 void ReportWebGPUSupportMetrics(dawn::native::Instance* instance) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static BASE_FEATURE(kCollectWebGPUSupportMetrics,
                       "CollectWebGPUSupportMetrics",
                       base::FEATURE_DISABLED_BY_DEFAULT);
