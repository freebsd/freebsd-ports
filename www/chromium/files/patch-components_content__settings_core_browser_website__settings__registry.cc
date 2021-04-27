--- components/content_settings/core/browser/website_settings_registry.cc.orig	2021-04-14 18:40:59 UTC
+++ components/content_settings/core/browser/website_settings_registry.cc
@@ -69,7 +69,7 @@ const WebsiteSettingsInfo* WebsiteSettingsRegistry::Re
     return nullptr;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   if (!(platform & PLATFORM_LINUX))
     return nullptr;
 #elif defined(OS_MAC)
