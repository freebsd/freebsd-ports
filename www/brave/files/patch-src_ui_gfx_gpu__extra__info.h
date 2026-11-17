--- src/ui/gfx/gpu_extra_info.h.orig	2026-10-18 18:43:23 UTC
+++ src/ui/gfx/gpu_extra_info.h
@@ -47,7 +47,7 @@ struct COMPONENT_EXPORT(GFX) GpuExtraInf
   // applicable.
   ANGLEFeatures angle_features;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_gmb_nv12_supported = false;
 #endif
 };
