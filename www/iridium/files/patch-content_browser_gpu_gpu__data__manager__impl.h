--- content/browser/gpu/gpu_data_manager_impl.h.orig	2026-06-10 12:51:34 UTC
+++ content/browser/gpu/gpu_data_manager_impl.h
@@ -234,7 +234,7 @@ class CONTENT_EXPORT GpuDataManagerImpl : public GpuDa
   void OnDisplayMetricsChanged(const display::Display& display,
                                uint32_t changed_metrics) override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGpuMemoryBufferNV12Supported();
 #endif  // BUILDFLAG(IS_LINUX)
 
