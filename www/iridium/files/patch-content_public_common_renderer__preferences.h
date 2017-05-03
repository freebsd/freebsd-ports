--- content/public/common/renderer_preferences.h.orig	2017-04-19 19:06:34 UTC
+++ content/public/common/renderer_preferences.h
@@ -131,7 +131,7 @@ struct CONTENT_EXPORT RendererPreference
   // Country iso of the mobile network for content detection purpose.
   std::string network_contry_iso;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::string system_font_family_name;
 #endif
 
