--- src/content/browser/gpu/gpu_data_manager_impl.cc.orig	2026-10-18 18:43:23 UTC
+++ src/content/browser/gpu/gpu_data_manager_impl.cc
@@ -411,7 +411,7 @@ void GpuDataManagerImpl::OnDisplayMetric
   private_->OnDisplayMetricsChanged(display, changed_metrics);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuDataManagerImpl::IsGpuMemoryBufferNV12Supported() {
   base::AutoLock auto_lock(lock_);
   return private_->IsGpuMemoryBufferNV12Supported();
