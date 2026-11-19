--- chrome/browser/ui/browser_commands.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/browser_commands.cc
@@ -280,7 +280,7 @@
 #include "chrome/browser/ui/views/contextual_tasks/contextual_tasks_close_button_controller.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/scheduled_restart/scheduled_restart_bubble_controller.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -1418,7 +1418,7 @@ void NewTabToRight(BrowserWindowInterface* browser) {
 }
 
 void NewTabFromClipboardURL(BrowserWindowInterface* browser) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (ui::Clipboard::IsSupportedClipboardBuffer(
           ui::ClipboardBuffer::kSelection)) {
     ui::Clipboard* clipboard = ui::Clipboard::GetForCurrentThread();
@@ -2848,7 +2848,7 @@ void MaybeUpdateChrome(BrowserWindowInterface* browser
     ShowOutdatedUpgradeBubble(browser, browser,
                               /*auto_update_enabled=*/false);
   } else {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     chrome::AttemptRelaunch();
 #else
     base::RecordAction(UserMetricsAction("UpdateChrome"));
@@ -2857,7 +2857,7 @@ void MaybeUpdateChrome(BrowserWindowInterface* browser
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void OpenScheduledRestartDialog(BrowserWindowInterface* browser) {
   if (auto* controller =
           scheduled_restart::ScheduledRestartBubbleController::From(
