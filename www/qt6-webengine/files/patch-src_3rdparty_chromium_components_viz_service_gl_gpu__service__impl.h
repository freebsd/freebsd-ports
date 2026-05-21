--- src/3rdparty/chromium/components/viz/service/gl/gpu_service_impl.h.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/components/viz/service/gl/gpu_service_impl.h
@@ -456,7 +456,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
