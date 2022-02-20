--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -384,7 +384,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #endif
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
