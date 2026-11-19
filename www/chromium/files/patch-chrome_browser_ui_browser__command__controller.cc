--- chrome/browser/ui/browser_command_controller.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/browser_command_controller.cc
@@ -187,7 +187,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ime/text_edit_commands.h"
 #include "ui/base/ime/text_input_flags.h"
 #include "ui/linux/linux_ui.h"
@@ -197,7 +197,7 @@
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/shortcuts/desktop_shortcuts_utils.h"
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 
@@ -543,7 +543,7 @@ bool BrowserCommandController::IsReservedCommandOrKey(
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If this key was registered by the user as a content editing hotkey, then
   // it is not reserved.
   auto* linux_ui = ui::LinuxUi::instance();
@@ -909,7 +909,7 @@ void BrowserCommandController::HandleCommandWithDispos
       break;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     case IDC_MINIMIZE_WINDOW:
       browser_->GetWindow()->Minimize();
       break;
@@ -922,7 +922,7 @@ void BrowserCommandController::HandleCommandWithDispos
 
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case IDC_USE_SYSTEM_TITLE_BAR: {
       PrefService* prefs = profile()->GetPrefs();
       prefs->SetBoolean(prefs::kUseCustomChromeFrame,
@@ -1184,7 +1184,7 @@ void BrowserCommandController::HandleCommandWithDispos
       break;
     case IDC_CREATE_SHORTCUT:
       base::RecordAction(base::UserMetricsAction("CreateShortcut"));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       chrome::CreateDesktopShortcutForActiveWebContents(browser_);
 #else
       web_app::CreateWebAppFromCurrentWebContents(
@@ -1390,7 +1390,7 @@ void BrowserCommandController::HandleCommandWithDispos
     case IDC_UPGRADE_DIALOG:
       MaybeUpdateChrome(browser_);
       break;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case IDC_SCHEDULED_RESTART_DIALOG:
       OpenScheduledRestartDialog(browser_);
       break;
@@ -1414,7 +1414,7 @@ void BrowserCommandController::HandleCommandWithDispos
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
     case IDC_CHROME_WHATS_NEW:
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
       ShowChromeWhatsNew(browser_);
       break;
 #else
@@ -1870,13 +1870,13 @@ void BrowserCommandController::InitCommandState() {
   command_updater_->UpdateCommandEnabled(IDC_VISIT_DESKTOP_OF_LRU_USER_4, true);
   command_updater_->UpdateCommandEnabled(IDC_VISIT_DESKTOP_OF_LRU_USER_5, true);
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   command_updater_->UpdateCommandEnabled(IDC_MINIMIZE_WINDOW, true);
   command_updater_->UpdateCommandEnabled(IDC_MAXIMIZE_WINDOW, true);
   command_updater_->UpdateCommandEnabled(IDC_RESTORE_WINDOW, true);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool use_system_title_bar = true;
 #if BUILDFLAG(IS_OZONE)
   use_system_title_bar = ui::OzonePlatform::GetInstance()
@@ -2069,7 +2069,7 @@ void BrowserCommandController::InitCommandState() {
 
   // These are always enabled; the menu determines their menu item visibility.
   command_updater_->UpdateCommandEnabled(IDC_UPGRADE_DIALOG, true);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   command_updater_->UpdateCommandEnabled(IDC_SCHEDULED_RESTART_DIALOG, true);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
   command_updater_->UpdateCommandEnabled(IDC_SET_BROWSER_AS_DEFAULT, true);
@@ -2290,7 +2290,7 @@ void BrowserCommandController::UpdateCommandsForTabSta
   bool can_create_web_app = web_app::CanCreateWebApp(browser_);
   command_updater_->UpdateCommandEnabled(IDC_INSTALL_PWA, can_create_web_app);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   command_updater_->UpdateCommandEnabled(
       IDC_CREATE_SHORTCUT,
       shortcuts::CanCreateDesktopShortcut(current_web_contents));
