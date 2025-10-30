--- chrome/browser/ui/browser_command_controller.cc.orig	2025-10-30 15:44:36 UTC
+++ chrome/browser/ui/browser_command_controller.cc
@@ -129,7 +129,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ime/text_edit_commands.h"
 #include "ui/base/ime/text_input_flags.h"
 #include "ui/linux/linux_ui.h"
@@ -139,7 +139,7 @@
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/shortcuts/desktop_shortcuts_utils.h"
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 
@@ -373,7 +373,7 @@ bool BrowserCommandController::IsReservedCommandOrKey(
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If this key was registered by the user as a content editing hotkey, then
   // it is not reserved.
   auto* linux_ui = ui::LinuxUi::instance();
@@ -676,7 +676,7 @@ bool BrowserCommandController::ExecuteCommandWithDispo
       break;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case IDC_MINIMIZE_WINDOW:
       browser_->window()->Minimize();
       break;
@@ -898,7 +898,7 @@ bool BrowserCommandController::ExecuteCommandWithDispo
       break;
     case IDC_CREATE_SHORTCUT:
       base::RecordAction(base::UserMetricsAction("CreateShortcut"));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       chrome::CreateDesktopShortcutForActiveWebContents(browser_);
 #else
       web_app::CreateWebAppFromCurrentWebContents(
@@ -1075,7 +1075,7 @@ bool BrowserCommandController::ExecuteCommandWithDispo
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
     case IDC_CHROME_WHATS_NEW:
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
       ShowChromeWhatsNew(browser_);
       break;
 #else
@@ -1464,7 +1464,7 @@ void BrowserCommandController::InitCommandState() {
   command_updater_.UpdateCommandEnabled(IDC_VISIT_DESKTOP_OF_LRU_USER_4, true);
   command_updater_.UpdateCommandEnabled(IDC_VISIT_DESKTOP_OF_LRU_USER_5, true);
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   command_updater_.UpdateCommandEnabled(IDC_MINIMIZE_WINDOW, true);
   command_updater_.UpdateCommandEnabled(IDC_MAXIMIZE_WINDOW, true);
   command_updater_.UpdateCommandEnabled(IDC_RESTORE_WINDOW, true);
@@ -1824,7 +1824,7 @@ void BrowserCommandController::UpdateCommandsForTabSta
   bool can_create_web_app = web_app::CanCreateWebApp(browser_);
   command_updater_.UpdateCommandEnabled(IDC_INSTALL_PWA, can_create_web_app);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   command_updater_.UpdateCommandEnabled(
       IDC_CREATE_SHORTCUT,
       shortcuts::CanCreateDesktopShortcut(current_web_contents));
