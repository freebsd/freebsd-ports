--- content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2024-12-22 12:24:29 UTC
+++ content/browser/gpu/gpu_data_manager_impl_private.cc
@@ -1672,7 +1672,7 @@ void GpuDataManagerImplPrivate::RecordCompositingMode(
   UMA_HISTOGRAM_ENUMERATION("GPU.CompositingMode", compositing_mode);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuDataManagerImplPrivate::IsGpuMemoryBufferNV12Supported() {
   return is_gpu_memory_buffer_NV12_supported_;
 }
