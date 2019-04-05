--- content/public/common/renderer_preferences.h.orig	2019-03-11 22:00:58 UTC
+++ content/public/common/renderer_preferences.h
@@ -120,7 +120,7 @@ struct CONTENT_EXPORT RendererPreferences {
   // Country iso of the mobile network for content detection purpose.
   std::string network_contry_iso;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::string system_font_family_name;
 #endif
 
