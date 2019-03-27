--- src/3rdparty/chromium/components/content_settings/core/browser/website_settings_registry.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/components/content_settings/core/browser/website_settings_registry.cc
@@ -83,8 +83,8 @@ const WebsiteSettingsInfo* WebsiteSettingsRegistry::Re
   // doesn't allow the settings to be managed in the same way. See
   // crbug.com/642184.
   sync_status = WebsiteSettingsInfo::UNSYNCABLE;
-#elif defined(OS_IOS)
-  if (!(platform & PLATFORM_IOS))
+#elif defined(OS_IOS) || defined(OS_BSD)
+  if (!(platform & PLATFORM_IOS) || !(platform & PLATFORM_BSD))
     return nullptr;
   // Don't sync settings to mobile platforms. The UI is different to desktop and
   // doesn't allow the settings to be managed in the same way. See
