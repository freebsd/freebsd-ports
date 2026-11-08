--- components/viz/host/gpu_host_impl.cc.orig	2026-10-31 12:09:36 UTC
+++ components/viz/host/gpu_host_impl.cc
@@ -172,7 +172,7 @@ GpuHostImpl::GpuHostImpl(Delegate* delegate,
       mojom::GpuServiceCreationParams::New();
 #if BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux has an issue when running in single-process mode wherein
   // GetPlatformRuntimeProperties() browser-side calls can have a data race with
   // in-process GPU service initialization. The call to
