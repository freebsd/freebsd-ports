--- ui/gfx/font_render_params.h.orig	2017-07-25 21:05:19.000000000 +0200
+++ ui/gfx/font_render_params.h	2017-08-02 16:44:10.216212000 +0200
@@ -107,14 +107,14 @@
     const FontRenderParamsQuery& query,
     std::string* family_out);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Clears GetFontRenderParams()'s cache. Intended to be called by tests that are
 // changing Fontconfig's configuration.
 GFX_EXPORT void ClearFontRenderParamsCacheForTest();
 #endif
 
 #if defined(OS_CHROMEOS) || defined(OS_LINUX) || \
-    (defined(OS_ANDROID) && BUILDFLAG(ENABLE_VR))
+    (defined(OS_ANDROID) && BUILDFLAG(ENABLE_VR)) || defined(OS_BSD)
 // Gets the device scale factor to query the FontRenderParams.
 GFX_EXPORT float GetFontRenderParamsDeviceScaleFactor();
 
