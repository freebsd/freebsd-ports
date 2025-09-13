--- content/browser/gpu/gpu_data_manager_impl.h.orig	2025-09-11 13:19:19 UTC
+++ content/browser/gpu/gpu_data_manager_impl.h
@@ -224,7 +224,7 @@ class CONTENT_EXPORT GpuDataManagerImpl : public GpuDa
   void OnDisplayMetricsChanged(const display::Display& display,
                                uint32_t changed_metrics) override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGpuMemoryBufferNV12Supported();
 #endif  // BUILDFLAG(IS_LINUX)
 
