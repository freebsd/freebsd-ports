--- content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2025-07-02 06:08:04 UTC
+++ content/browser/gpu/gpu_data_manager_impl_private.cc
@@ -1696,7 +1696,7 @@ void GpuDataManagerImplPrivate::RecordCompositingMode(
   UMA_HISTOGRAM_ENUMERATION("GPU.CompositingMode", compositing_mode);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuDataManagerImplPrivate::IsGpuMemoryBufferNV12Supported() {
   return gpu_extra_info_.is_gmb_nv12_supported;
 }
