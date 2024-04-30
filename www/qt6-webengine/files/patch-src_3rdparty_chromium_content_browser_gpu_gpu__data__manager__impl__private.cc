--- src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl_private.cc
@@ -1787,7 +1787,7 @@ void GpuDataManagerImplPrivate::RecordCompositingMode(
   UMA_HISTOGRAM_ENUMERATION("GPU.CompositingMode", compositing_mode);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuDataManagerImplPrivate::IsGpuMemoryBufferNV12Supported() {
   return is_gpu_memory_buffer_NV12_supported_;
 }
