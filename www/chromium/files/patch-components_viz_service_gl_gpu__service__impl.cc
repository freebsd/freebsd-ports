--- components/viz/service/gl/gpu_service_impl.cc.orig	2026-07-01 06:24:19 UTC
+++ components/viz/service/gl/gpu_service_impl.cc
@@ -458,7 +458,7 @@ void GpuServiceImpl::InitializeWithHostInternal(
 
   mojo::Remote<mojom::GpuHost> gpu_host(std::move(pending_gpu_host));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gpu_extra_info_.is_gmb_nv12_supported = IsGMBNV12Supported();
 #endif
 
@@ -1248,7 +1248,7 @@ bool GpuServiceImpl::OnBeginFrameDerivedImpl(const Beg
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuServiceImpl::IsGMBNV12Supported() {
   CHECK(main_runner_->BelongsToCurrentThread());
 
