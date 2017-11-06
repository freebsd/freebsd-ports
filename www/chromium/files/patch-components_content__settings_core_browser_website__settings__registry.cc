--- components/content_settings/core/browser/website_settings_registry.cc.orig	2017-09-05 21:05:17.000000000 +0200
+++ components/content_settings/core/browser/website_settings_registry.cc	2017-09-10 01:16:20.683275000 +0200
@@ -70,7 +70,7 @@
 #if defined(OS_WIN)
   if (!(platform & PLATFORM_WINDOWS))
     return nullptr;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (!(platform & PLATFORM_LINUX))
     return nullptr;
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
