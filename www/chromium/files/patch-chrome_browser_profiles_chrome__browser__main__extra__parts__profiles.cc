--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2022-07-22 17:30:31 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -414,7 +414,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #endif
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
