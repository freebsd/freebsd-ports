--- chrome/browser/ui/chrome_pages.cc.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/ui/chrome_pages.cc
@@ -85,12 +85,12 @@
 #include "components/signin/public/identity_manager/identity_manager.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/web_app_utils.h"
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -252,7 +252,7 @@ bool SiteGURLIsValid(const GURL& url) {
   return !site_origin.opaque() && (url.SchemeIsHTTPOrHTTPS() ||
                                    url.SchemeIs(extensions::kExtensionScheme)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                    || url.SchemeIs(webapps::kIsolatedAppScheme)
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -414,7 +414,7 @@ void ShowChromeTips(Browser* browser) {
   ShowSingletonTab(browser, GURL(kChromeTipsURL));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ShowChromeWhatsNew(Browser* browser) {
   ShowSingletonTab(browser, GURL(kChromeUIWhatsNewURL));
 }
@@ -743,7 +743,7 @@ void ShowShortcutCustomizationApp(Profile* profile,
 }
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ShowWebAppSettingsImpl(Browser* browser,
                             Profile* profile,
                             const std::string& app_id,
