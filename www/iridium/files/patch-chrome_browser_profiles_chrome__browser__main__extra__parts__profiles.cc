--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -326,7 +326,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if !defined(OS_ANDROID)
   MediaGalleriesPreferencesFactory::GetInstance();
 #endif
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
