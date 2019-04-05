--- src/3rdparty/chromium/content/public/common/renderer_preferences.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/public/common/renderer_preferences.h
@@ -137,7 +137,7 @@ struct CONTENT_EXPORT RendererPreferences {
   // Country iso of the mobile network for content detection purpose.
   std::string network_contry_iso;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::string system_font_family_name;
 #endif
 
