--- components/viz/service/gl/gpu_service_impl.h.orig	2025-12-05 10:12:50 UTC
+++ components/viz/service/gl/gpu_service_impl.h
@@ -442,7 +442,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
