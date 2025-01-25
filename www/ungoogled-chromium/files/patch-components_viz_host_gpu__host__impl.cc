--- components/viz/host/gpu_host_impl.cc.orig	2025-01-25 09:34:31 UTC
+++ components/viz/host/gpu_host_impl.cc
@@ -139,7 +139,7 @@ GpuHostImpl::GpuHostImpl(Delegate* delegate,
 // overlays are not currently supported on Linux, elide the call here at this
 // time.
 // TODO(crbug.com/377886734): Fix the underlying issue and re-enable this call.
-#if BUILDFLAG(IS_OZONE) && !BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_OZONE) && (!BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD))
   gpu_service_params->supports_overlays = ui::OzonePlatform::GetInstance()
                                               ->GetPlatformRuntimeProperties()
                                               .supports_overlays;
