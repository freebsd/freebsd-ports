--- ui/gfx/font_render_params.h.orig	2026-08-13 07:41:05 UTC
+++ ui/gfx/font_render_params.h
@@ -115,12 +115,12 @@ COMPONENT_EXPORT(GFX)
 FontRenderParams GetFontRenderParams(const FontRenderParamsQuery& query,
                                      std::string* family_out);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Clears GetFontRenderParams()'s cache.
 COMPONENT_EXPORT(GFX) void ClearFontRenderParamsCache();
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/517630459) Return this to `ForTesting()` after per display
 // subpixel rendering is implemented.
 COMPONENT_EXPORT(GFX) bool GetFontRenderParamsSubpixelRenderingEnabled();
@@ -130,7 +130,7 @@ COMPONENT_EXPORT(GFX) bool GetFontRenderParamsSubpixel
 COMPONENT_EXPORT(GFX) float GetFontRenderParamsDeviceScaleFactor();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Sets the device scale factor for FontRenderParams to decide
 // if it should enable subpixel positioning.
 COMPONENT_EXPORT(GFX)
