--- components/viz/service/gl/gpu_service_impl.cc.orig	2026-02-19 11:06:15 UTC
+++ components/viz/service/gl/gpu_service_impl.cc
@@ -478,7 +478,7 @@ void GpuServiceImpl::InitializeWithHostInternal(
 
   mojo::Remote<mojom::GpuHost> gpu_host(std::move(pending_gpu_host));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gpu_extra_info_.is_gmb_nv12_supported = IsGMBNV12Supported();
 #endif
 
@@ -1236,7 +1236,7 @@ bool GpuServiceImpl::OnBeginFrameDerivedImpl(const Beg
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuServiceImpl::IsGMBNV12Supported() {
   CHECK(main_runner_->BelongsToCurrentThread());
 
