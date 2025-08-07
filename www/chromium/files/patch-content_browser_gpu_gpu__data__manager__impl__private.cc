--- content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2025-08-07 06:57:29 UTC
+++ content/browser/gpu/gpu_data_manager_impl_private.cc
@@ -1703,7 +1703,7 @@ void GpuDataManagerImplPrivate::RecordCompositingMode(
   UMA_HISTOGRAM_ENUMERATION("GPU.CompositingMode", compositing_mode);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuDataManagerImplPrivate::IsGpuMemoryBufferNV12Supported() {
   return gpu_extra_info_.is_gmb_nv12_supported;
 }
