--- src/3rdparty/chromium/components/content_settings/core/browser/website_settings_registry.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/components/content_settings/core/browser/website_settings_registry.cc
@@ -66,7 +66,7 @@ const WebsiteSettingsInfo* WebsiteSettingsRegistry::Re
 #if defined(OS_WIN)
   if (!(platform & PLATFORM_WINDOWS))
     return nullptr;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (!(platform & PLATFORM_LINUX))
     return nullptr;
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
