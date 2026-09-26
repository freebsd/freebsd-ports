--- chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc
@@ -90,7 +90,7 @@
 #include "chrome/browser/ui/cocoa/keystone_infobar_delegate.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_manager.h"  // nogncheck
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_prefs.h"  // nogncheck
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_manager.h"
@@ -141,7 +141,7 @@ TriggerRequirements RequirementsFor(InfoBarType type) 
       return {.profile = true, .web_contents = true};
 #endif
     case InfoBarType::kExtensionDevTools:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kDefaultBrowser:
     case InfoBarType::kSessionRestore:
 #endif
@@ -200,7 +200,7 @@ void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsC
             "The Collected Cookies infobar is shown after the user has changed "
             "the allowed/blocked state of a cookie, reminding them to reload "
             "the page in order for the new cookies to take effect.");
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   add_entry(InfoBarType::kDefaultBrowser, "Default Browser",
             "The Default Browser infobar asks the user if they want to set "
             "Chrome as their default browser. This trigger resets any browser "
@@ -284,7 +284,7 @@ void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsC
             "shows the infobar.");
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   add_entry(InfoBarType::kSessionRestore, "Session Restore",
             "Triggers the session restore infobar. This infobar can only be "
             "triggered on Mac, Windows and Linux.");
@@ -362,7 +362,7 @@ bool InfoBarInternalsHandler::TriggerInfoBarInternal(I
       }
       return true;
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kDefaultBrowser: {
       chrome::startup::default_prompt::ResetPromptPrefs(profile);
       DefaultBrowserPromptManager::GetInstance()->MaybeShowPrompt();
@@ -666,7 +666,7 @@ bool InfoBarInternalsHandler::TriggerInfoBarInternal(I
       return true;
     }
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kSessionRestore: {
       session_restore_infobar::SessionRestoreInfoBarManager::GetInstance()
           ->ShowInfoBar(*profile,
