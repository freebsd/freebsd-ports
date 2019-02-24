--- ui/gfx/font_render_params.h.orig	2019-01-30 02:18:54.000000000 +0100
+++ ui/gfx/font_render_params.h	2019-02-01 15:04:34.285442000 +0100
@@ -111,13 +111,13 @@
     const FontRenderParamsQuery& query,
     std::string* family_out);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Clears GetFontRenderParams()'s cache. Intended to be called by tests that are
 // changing Fontconfig's configuration.
 GFX_EXPORT void ClearFontRenderParamsCacheForTest();
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Gets the device scale factor to query the FontRenderParams.
 GFX_EXPORT float GetFontRenderParamsDeviceScaleFactor();
 
