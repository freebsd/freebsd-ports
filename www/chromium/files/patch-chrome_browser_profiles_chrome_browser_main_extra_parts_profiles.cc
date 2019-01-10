--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2019-01-10 01:15:46.031074000 +0100
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc	2019-01-10 01:16:16.877359000 +0100
@@ -317,7 +317,7 @@
 #if !defined(OS_ANDROID)
   MediaGalleriesPreferencesFactory::GetInstance();
 #endif
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
