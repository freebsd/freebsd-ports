--- components/viz/service/gl/gpu_service_impl.cc.orig	2026-11-17 11:49:09 UTC
+++ components/viz/service/gl/gpu_service_impl.cc
@@ -505,7 +505,7 @@ void GpuServiceImpl::InitializeWithHostInternal(
 
   mojo::Remote<mojom::GpuHost> gpu_host(std::move(pending_gpu_host));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gpu_extra_info_.is_gmb_nv12_supported = IsGMBNV12Supported();
 #endif
 
@@ -1300,7 +1300,7 @@ bool GpuServiceImpl::OnBeginFrameDerivedImpl(const Beg
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuServiceImpl::IsGMBNV12Supported() {
   CHECK(main_runner_->BelongsToCurrentThread());
 
