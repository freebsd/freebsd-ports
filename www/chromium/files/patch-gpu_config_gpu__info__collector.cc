--- gpu/config/gpu_info_collector.cc.orig	2026-11-19 12:25:27 UTC
+++ gpu/config/gpu_info_collector.cc
@@ -366,7 +366,7 @@ void ReportWebGPUAdapterMetrics(dawn::native::Instance
 
 void ReportWebGPUSupportMetrics(dawn::native::Instance* instance) {
   static BASE_FEATURE(kCollectWebGPUSupportMetrics,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                       base::FEATURE_DISABLED_BY_DEFAULT);
 #else
                       base::FEATURE_ENABLED_BY_DEFAULT);
@@ -946,7 +946,7 @@ void CollectDawnInfo(const gpu::GpuPreferences& gpu_pr
 #if BUILDFLAG(IS_WIN)
       {wgpu::FeatureLevel::Compatibility, wgpu::BackendType::D3D11},
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       {wgpu::FeatureLevel::Compatibility, wgpu::BackendType::OpenGL},
 #endif
   };
