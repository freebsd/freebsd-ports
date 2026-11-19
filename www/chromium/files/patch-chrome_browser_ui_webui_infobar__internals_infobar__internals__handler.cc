--- chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc
@@ -103,7 +103,7 @@
 #include "chrome/browser/ui/cocoa/keystone_infobar_delegate.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/apps/link_capturing/enable_link_capturing_infobar_delegate.h"
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_manager.h"
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_prefs.h"
@@ -170,7 +170,7 @@ TriggerRequirements RequirementsFor(InfoBarType type) 
     case InfoBarType::kSigninQRCode:
 #endif
       return {.web_contents = true};
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kEnableLinkCapturing:
       return {.profile = true, .web_contents = true};
 #endif
@@ -181,7 +181,7 @@ TriggerRequirements RequirementsFor(InfoBarType type) 
       return {.profile = true, .web_contents = true};
 #endif
     case InfoBarType::kExtensionDevTools:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kDefaultBrowser:
     case InfoBarType::kSessionRestore:
 #endif
@@ -300,7 +300,7 @@ void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsC
             "The Collected Cookies infobar is shown after the user has changed "
             "the allowed/blocked state of a cookie, reminding them to reload "
             "the page in order for the new cookies to take effect.");
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   add_entry(InfoBarType::kDefaultBrowser, "Default Browser",
             "The Default Browser infobar asks the user if they want to set "
             "Chrome as their default browser. This trigger resets any browser "
@@ -324,7 +324,7 @@ void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsC
             "process-per-site disabled. This trigger shows the infobar on the "
             "active tab.");
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   add_entry(InfoBarType::kEnableLinkCapturing, "Enable Link Capturing",
             "The Enable Link Capturing infobar asks the user if they want to "
             "open supported links in an installed web app. This trigger "
@@ -416,7 +416,7 @@ void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsC
             "Mac.");
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   add_entry(InfoBarType::kSessionRestore, "Session Restore",
             "Triggers the session restore infobar. This infobar can only be "
             "triggered on Mac, Windows and Linux.");
@@ -562,7 +562,7 @@ bool InfoBarInternalsHandler::PerformInfoBarActionInte
       }
       return true;
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kDefaultBrowser: {
       chrome::startup::default_prompt::ResetPromptPrefs(profile);
       DefaultBrowserPromptManager::GetInstance()->MaybeShowPrompt();
@@ -619,7 +619,7 @@ bool InfoBarInternalsHandler::PerformInfoBarActionInte
                  std::make_unique<ProcessSharingInfobarDelegate>(
                      web_contents))) != nullptr;
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kEnableLinkCapturing: {
       std::string app_id = "example_app_id";
       std::u16string app_name = u"Example App";
@@ -1020,7 +1020,7 @@ bool InfoBarInternalsHandler::PerformInfoBarActionInte
     }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kSessionRestore: {
       session_restore_infobar::SessionRestoreInfoBarManager::GetInstance()
           ->ShowInfoBar(
