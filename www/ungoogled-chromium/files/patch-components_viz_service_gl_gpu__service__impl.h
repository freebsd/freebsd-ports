--- components/viz/service/gl/gpu_service_impl.h.orig	2026-01-16 13:40:34 UTC
+++ components/viz/service/gl/gpu_service_impl.h
@@ -440,7 +440,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
