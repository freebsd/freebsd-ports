--- content/browser/gpu/gpu_data_manager_impl.cc.orig	2024-06-17 12:56:06 UTC
+++ content/browser/gpu/gpu_data_manager_impl.cc
@@ -397,7 +397,7 @@ void GpuDataManagerImpl::OnDisplayMetricsChanged(
   private_->OnDisplayMetricsChanged(display, changed_metrics);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuDataManagerImpl::IsGpuMemoryBufferNV12Supported() {
   base::AutoLock auto_lock(lock_);
   return private_->IsGpuMemoryBufferNV12Supported();
