--- components/content_settings/core/browser/website_settings_registry.cc.orig	2016-10-06 04:02:16.000000000 +0300
+++ components/content_settings/core/browser/website_settings_registry.cc	2016-10-13 13:04:35.828985000 +0300
@@ -88,6 +88,9 @@
   // doesn't allow the settings to be managed in the same way. See
   // crbug.com/642184.
   sync_status = WebsiteSettingsInfo::UNSYNCABLE;
+#elif defined(OS_BSD)
+  if (!(platform & PLATFORM_BSD))
+    return nullptr;
 #else
 #error "Unsupported platform"
 #endif
