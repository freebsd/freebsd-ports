--- ui/gfx/font_render_params.h.orig	2020-11-13 06:37:06 UTC
+++ ui/gfx/font_render_params.h
@@ -111,7 +111,7 @@ GFX_EXPORT FontRenderParams GetFontRenderParams(
     const FontRenderParamsQuery& query,
     std::string* family_out);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Clears GetFontRenderParams()'s cache. Intended to be called by tests that are
 // changing Fontconfig's configuration.
 GFX_EXPORT void ClearFontRenderParamsCacheForTest();
@@ -120,7 +120,7 @@ GFX_EXPORT void ClearFontRenderParamsCacheForTest();
 // Gets the device scale factor to query the FontRenderParams.
 GFX_EXPORT float GetFontRenderParamsDeviceScaleFactor();
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_ANDROID) || defined(OS_FUCHSIA)
 // Sets the device scale factor for FontRenderParams to decide
 // if it should enable subpixel positioning.
