--- chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc.orig	2026-11-11 14:44:17 UTC
+++ chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc
@@ -99,7 +99,7 @@
 #include "chrome/browser/ui/cocoa/keystone_infobar_delegate.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_manager.h"
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_prefs.h"
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_manager.h"
@@ -171,7 +171,7 @@ TriggerRequirements RequirementsFor(InfoBarType type) 
       return {.profile = true, .web_contents = true};
 #endif
     case InfoBarType::kExtensionDevTools:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kDefaultBrowser:
     case InfoBarType::kEnableLinkCapturing:
     case InfoBarType::kSessionRestore:
@@ -293,7 +293,7 @@ void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsC
             "The Collected Cookies infobar is shown after the user has changed "
             "the allowed/blocked state of a cookie, reminding them to reload "
             "the page in order for the new cookies to take effect.");
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   add_entry(InfoBarType::kDefaultBrowser, "Default Browser",
             "The Default Browser infobar asks the user if they want to set "
             "Chrome as their default browser. This trigger resets any browser "
@@ -317,7 +317,7 @@ void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsC
             "process-per-site disabled. This trigger shows the infobar on the "
             "active tab.");
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   add_entry(InfoBarType::kEnableLinkCapturing, "Enable Link Capturing",
             "The Enable Link Capturing infobar asks the user if they want to "
             "open supported links in an installed web app. This trigger "
@@ -409,7 +409,7 @@ void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsC
             "Mac.");
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   add_entry(InfoBarType::kSessionRestore, "Session Restore",
             "Triggers the session restore infobar. This infobar can only be "
             "triggered on Mac, Windows and Linux.");
@@ -550,7 +550,7 @@ bool InfoBarInternalsHandler::PerformInfoBarActionInte
       }
       return true;
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kDefaultBrowser: {
       chrome::startup::default_prompt::ResetPromptPrefs(profile);
       DefaultBrowserPromptManager::GetInstance()->MaybeShowPrompt();
@@ -596,7 +596,7 @@ bool InfoBarInternalsHandler::PerformInfoBarActionInte
                  std::make_unique<ProcessSharingInfobarDelegate>(
                      web_contents))) != nullptr;
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kEnableLinkCapturing: {
       if (!infobars::IsInfoBarMigrated(
               infobars::InfoBarDelegate::
@@ -967,7 +967,7 @@ bool InfoBarInternalsHandler::PerformInfoBarActionInte
     }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kSessionRestore: {
       session_restore_infobar::SessionRestoreInfoBarManager::GetInstance()
           ->ShowInfoBar(
