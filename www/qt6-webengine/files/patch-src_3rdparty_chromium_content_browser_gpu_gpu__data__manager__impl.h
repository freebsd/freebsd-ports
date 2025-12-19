--- src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl.h
@@ -220,7 +220,7 @@ class CONTENT_EXPORT GpuDataManagerImpl : public GpuDa
   void OnDisplayMetricsChanged(const display::Display& display,
                                uint32_t changed_metrics) override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGpuMemoryBufferNV12Supported();
   void SetGpuMemoryBufferNV12Supported(bool supported);
 #endif  // BUILDFLAG(IS_LINUX)
