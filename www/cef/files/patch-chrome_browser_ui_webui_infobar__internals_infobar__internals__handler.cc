--- chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc
@@ -67,7 +67,7 @@
 #include "chrome/browser/ui/cocoa/keystone_infobar_delegate.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_manager.h"  // nogncheck
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_prefs.h"  // nogncheck
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_delegate.h"
@@ -114,7 +114,7 @@ void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsC
       "The Collected Cookies infobar is shown after the user has changed "
       "the allowed/blocked state of a cookie, reminding them to reload "
       "the page in order for the new cookies to take effect."));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   infobar_list.emplace_back(InfoBarEntry::New(
       /*type=*/InfoBarType::kDefaultBrowser, /*name=*/"Default Browser",
       /*description=*/
@@ -261,7 +261,7 @@ bool InfoBarInternalsHandler::TriggerInfoBarInternal(I
       }
       return true;
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kDefaultBrowser: {
       if (!profile) {
         return false;
