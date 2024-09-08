--- chrome/browser/sessions/session_restore.cc.orig	2024-08-26 12:06:38 UTC
+++ chrome/browser/sessions/session_restore.cc
@@ -99,7 +99,7 @@
 #include "chrome/browser/web_applications/web_app_registrar.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/whats_new/whats_new_fetcher.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -1049,7 +1049,7 @@ class SessionRestoreImpl : public BrowserListObserver 
     bool is_first_tab = true;
     for (const auto& startup_tab : startup_tabs) {
       const GURL& url = startup_tab.url;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (url == whats_new::GetWebUIStartupURL()) {
         whats_new::StartWhatsNewFetch(browser);
         continue;
