--- components/viz/host/gpu_host_impl.cc.orig	2025-12-05 10:12:50 UTC
+++ components/viz/host/gpu_host_impl.cc
@@ -157,7 +157,7 @@ GpuHostImpl::GpuHostImpl(Delegate* delegate,
       mojom::GpuServiceCreationParams::New();
 #if BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux has an issue when running in single-process mode wherein
   // GetPlatformRuntimeProperties() browser-side calls can have a data race with
   // in-process GPU service initialization. The call to
