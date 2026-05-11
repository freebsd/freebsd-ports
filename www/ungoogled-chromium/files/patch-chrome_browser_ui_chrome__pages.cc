--- chrome/browser/ui/chrome_pages.cc.orig	2026-05-09 18:09:27 UTC
+++ chrome/browser/ui/chrome_pages.cc
@@ -84,12 +84,12 @@
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
@@ -255,7 +255,7 @@ bool SiteGURLIsValid(const GURL& url) {
   return !site_origin.opaque() && (url.SchemeIsHTTPOrHTTPS() ||
                                    url.SchemeIs(extensions::kExtensionScheme)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                    || url.SchemeIs(webapps::kIsolatedAppScheme)
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -408,7 +408,7 @@ void ShowChromeTips(BrowserWindowInterface* browser) {
   ShowSingletonTab(browser, GURL(kChromeTipsURL));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ShowChromeWhatsNew(BrowserWindowInterface* browser) {
   ShowSingletonTab(browser, GURL(kChromeUIWhatsNewURL));
 }
@@ -699,7 +699,7 @@ void ShowSharedTabGroupActivity(Profile* profile) {
                    GURL(data_sharing::features::kActivityLogsURL.Get()));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ShowWebAppSettingsImpl(BrowserWindowInterface* browser,
                             Profile* profile,
                             const std::string& app_id,
