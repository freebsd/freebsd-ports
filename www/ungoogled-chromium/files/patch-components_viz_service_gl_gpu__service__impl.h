--- components/viz/service/gl/gpu_service_impl.h.orig	2025-11-01 06:40:37 UTC
+++ components/viz/service/gl/gpu_service_impl.h
@@ -448,7 +448,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
