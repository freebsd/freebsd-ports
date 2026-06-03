--- ui/gfx/gpu_extra_info.h.orig	2026-01-16 14:21:21 UTC
+++ ui/gfx/gpu_extra_info.h
@@ -47,7 +47,7 @@ struct COMPONENT_EXPORT(GFX) GpuExtraInfo {
   // applicable.
   ANGLEFeatures angle_features;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_gmb_nv12_supported = false;
 #endif
 };
