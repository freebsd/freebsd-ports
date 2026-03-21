--- components/viz/service/gl/gpu_service_impl.h.orig	2026-03-13 06:02:14 UTC
+++ components/viz/service/gl/gpu_service_impl.h
@@ -439,7 +439,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
