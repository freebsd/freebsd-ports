--- src/ui/gfx/platform_font_skia.h.orig	2026-10-18 18:43:23 UTC
+++ src/ui/gfx/platform_font_skia.h
@@ -101,7 +101,7 @@ class COMPONENT_EXPORT(GFX) PlatformFont
   int font_size_pixels_;
   int style_;
   float device_scale_factor_;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool subpixel_rendering_enabled_ = true;
 #endif
 
