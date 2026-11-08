--- content/browser/gpu/gpu_data_manager_impl_private.h.orig	2026-08-13 16:48:13 UTC
+++ content/browser/gpu/gpu_data_manager_impl_private.h
@@ -148,7 +148,7 @@ class CONTENT_EXPORT GpuDataManagerImplPrivate {
   void OnDisplayMetricsChanged(const display::Display& display,
                                uint32_t changed_metrics);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGpuMemoryBufferNV12Supported();
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -308,7 +308,7 @@ class CONTENT_EXPORT GpuDataManagerImplPrivate {
   bool application_is_visible_ = true;
 
   bool disable_gpu_compositing_ = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_gpu_memory_buffer_NV12_supported_ = false;
 #endif  // BUILDFLAG(IS_LINUX)
 
