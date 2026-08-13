--- content/browser/gpu/gpu_data_manager_impl.h.orig	2026-08-13 07:41:05 UTC
+++ content/browser/gpu/gpu_data_manager_impl.h
@@ -227,7 +227,7 @@ class CONTENT_EXPORT GpuDataManagerImpl : public GpuDa
   void OnDisplayMetricsChanged(const display::Display& display,
                                uint32_t changed_metrics) override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGpuMemoryBufferNV12Supported();
 #endif  // BUILDFLAG(IS_LINUX)
 
