--- ui/gfx/gpu_extra_info.h.orig	2025-07-02 06:08:04 UTC
+++ ui/gfx/gpu_extra_info.h
@@ -51,7 +51,7 @@ struct COMPONENT_EXPORT(GFX) GpuExtraInfo {
   std::vector<gfx::BufferUsageAndFormat> gpu_memory_buffer_support_x11;
 #endif  // BUILDFLAG(IS_OZONE_X11)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_gmb_nv12_supported = false;
 #endif
 };
