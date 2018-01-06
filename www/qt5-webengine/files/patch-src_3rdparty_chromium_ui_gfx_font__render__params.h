--- src/3rdparty/chromium/ui/gfx/font_render_params.h.orig	2017-01-26 00:49:31 UTC
+++ src/3rdparty/chromium/ui/gfx/font_render_params.h
@@ -106,13 +106,13 @@ GFX_EXPORT FontRenderParams GetFontRende
     const FontRenderParamsQuery& query,
     std::string* family_out);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Clears GetFontRenderParams()'s cache. Intended to be called by tests that are
 // changing Fontconfig's configuration.
 GFX_EXPORT void ClearFontRenderParamsCacheForTest();
 #endif
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 // Gets the device scale factor to query the FontRenderParams.
 GFX_EXPORT float GetFontRenderParamsDeviceScaleFactor();
 
