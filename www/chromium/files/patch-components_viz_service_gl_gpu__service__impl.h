--- components/viz/service/gl/gpu_service_impl.h.orig	2026-02-11 09:05:39 UTC
+++ components/viz/service/gl/gpu_service_impl.h
@@ -438,7 +438,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
