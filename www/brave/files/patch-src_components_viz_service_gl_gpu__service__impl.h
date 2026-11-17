--- src/components/viz/service/gl/gpu_service_impl.h.orig	2026-10-18 18:43:23 UTC
+++ src/components/viz/service/gl/gpu_service_impl.h
@@ -451,7 +451,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
