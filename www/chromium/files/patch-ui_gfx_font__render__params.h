--- ui/gfx/font_render_params.h.orig	2022-02-07 13:39:41 UTC
+++ ui/gfx/font_render_params.h
@@ -109,7 +109,7 @@ GFX_EXPORT FontRenderParams GetFontRenderParams(
     const FontRenderParamsQuery& query,
     std::string* family_out);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Clears GetFontRenderParams()'s cache. Intended to be called by tests that are
 // changing Fontconfig's configuration.
 GFX_EXPORT void ClearFontRenderParamsCacheForTest();
@@ -119,7 +119,7 @@ GFX_EXPORT void ClearFontRenderParamsCacheForTest();
 GFX_EXPORT float GetFontRenderParamsDeviceScaleFactor();
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_ANDROID) || defined(OS_FUCHSIA)
+    defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Sets the device scale factor for FontRenderParams to decide
 // if it should enable subpixel positioning.
 GFX_EXPORT void SetFontRenderParamsDeviceScaleFactor(
