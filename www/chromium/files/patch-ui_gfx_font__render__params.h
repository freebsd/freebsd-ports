--- ui/gfx/font_render_params.h.orig	2017-12-15 02:04:51.000000000 +0100
+++ ui/gfx/font_render_params.h	2017-12-24 20:14:06.436950000 +0100
@@ -107,13 +107,13 @@
     const FontRenderParamsQuery& query,
     std::string* family_out);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Clears GetFontRenderParams()'s cache. Intended to be called by tests that are
 // changing Fontconfig's configuration.
 GFX_EXPORT void ClearFontRenderParamsCacheForTest();
 #endif
 
-#if defined(OS_LINUX) || (defined(OS_ANDROID) && BUILDFLAG(ENABLE_VR))
+#if defined(OS_LINUX) || defined(OS_BSD) || (defined(OS_ANDROID) && BUILDFLAG(ENABLE_VR))
 // Gets the device scale factor to query the FontRenderParams.
 GFX_EXPORT float GetFontRenderParamsDeviceScaleFactor();
 
