--- src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl.h.orig	2023-04-28 17:01:32 UTC
+++ src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl.h
@@ -221,7 +221,7 @@ class CONTENT_EXPORT GpuDataManagerImpl : public GpuDa
   void OnDisplayMetricsChanged(const display::Display& display,
                                uint32_t changed_metrics) override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGpuMemoryBufferNV12Supported();
   void SetGpuMemoryBufferNV12Supported(bool supported);
 #endif  // BUILDFLAG(IS_LINUX)
