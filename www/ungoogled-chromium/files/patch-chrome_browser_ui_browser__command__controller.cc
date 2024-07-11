--- chrome/browser/ui/browser_command_controller.cc.orig	2024-06-22 08:49:42 UTC
+++ chrome/browser/ui/browser_command_controller.cc
@@ -126,7 +126,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ime/text_input_flags.h"
 #include "ui/linux/linux_ui.h"
 #endif
@@ -308,7 +308,7 @@ bool BrowserCommandController::IsReservedCommandOrKey(
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If this key was registered by the user as a content editing hotkey, then
   // it is not reserved.
   auto* linux_ui = ui::LinuxUi::instance();
@@ -560,7 +560,7 @@ bool BrowserCommandController::ExecuteCommandWithDispo
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     case IDC_MINIMIZE_WINDOW:
       browser_->window()->Minimize();
       break;
@@ -572,7 +572,7 @@ bool BrowserCommandController::ExecuteCommandWithDispo
       break;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case IDC_USE_SYSTEM_TITLE_BAR: {
       PrefService* prefs = profile()->GetPrefs();
       prefs->SetBoolean(prefs::kUseCustomChromeFrame,
@@ -766,7 +766,7 @@ bool BrowserCommandController::ExecuteCommandWithDispo
       break;
     case IDC_CREATE_SHORTCUT:
       base::RecordAction(base::UserMetricsAction("CreateShortcut"));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (base::FeatureList::IsEnabled(features::kShortcutsNotApps)) {
         chrome::CreateDesktopShortcutForActiveWebContents(browser_);
       } else {
@@ -1269,12 +1269,12 @@ void BrowserCommandController::InitCommandState() {
 #endif
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   command_updater_.UpdateCommandEnabled(IDC_MINIMIZE_WINDOW, true);
   command_updater_.UpdateCommandEnabled(IDC_MAXIMIZE_WINDOW, true);
   command_updater_.UpdateCommandEnabled(IDC_RESTORE_WINDOW, true);
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool use_system_title_bar = true;
 #if BUILDFLAG(IS_OZONE)
   use_system_title_bar = ui::OzonePlatform::GetInstance()
