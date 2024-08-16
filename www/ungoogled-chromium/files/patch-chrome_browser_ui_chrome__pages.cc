--- chrome/browser/ui/chrome_pages.cc.orig	2024-07-31 14:19:23 UTC
+++ chrome/browser/ui/chrome_pages.cc
@@ -85,7 +85,7 @@
 #include "components/signin/public/identity_manager/identity_manager.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/web_app_utils.h"
 #endif
 
@@ -378,7 +378,7 @@ void ShowChromeTips(Browser* browser) {
   ShowSingletonTab(browser, GURL(kChromeTipsURL));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ShowChromeWhatsNew(Browser* browser) {
   ShowSingletonTab(browser, GURL(kChromeUIWhatsNewURL));
 }
@@ -720,7 +720,7 @@ void ShowShortcutCustomizationApp(Profile* profile,
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ShowWebAppSettingsImpl(Browser* browser,
                             Profile* profile,
                             const std::string& app_id,
