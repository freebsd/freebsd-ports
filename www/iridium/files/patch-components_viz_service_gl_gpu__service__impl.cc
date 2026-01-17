--- components/viz/service/gl/gpu_service_impl.cc.orig	2026-01-16 14:21:21 UTC
+++ components/viz/service/gl/gpu_service_impl.cc
@@ -464,7 +464,7 @@ void GpuServiceImpl::InitializeWithHostInternal(
 
   mojo::Remote<mojom::GpuHost> gpu_host(std::move(pending_gpu_host));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gpu_extra_info_.is_gmb_nv12_supported = IsGMBNV12Supported();
 #endif
 
@@ -1228,7 +1228,7 @@ bool GpuServiceImpl::OnBeginFrameDerivedImpl(const Beg
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuServiceImpl::IsGMBNV12Supported() {
   CHECK(main_runner_->BelongsToCurrentThread());
 
