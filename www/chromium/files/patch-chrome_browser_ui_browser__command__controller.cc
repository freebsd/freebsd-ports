--- chrome/browser/ui/browser_command_controller.cc.orig	2017-03-09 20:04:29 UTC
+++ chrome/browser/ui/browser_command_controller.cc
@@ -80,7 +80,7 @@
 #include "chrome/browser/ui/browser_commands_chromeos.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "ui/base/ime/linux/text_edit_key_bindings_delegate_auralinux.h"
 #endif
 
@@ -202,7 +202,7 @@ bool BrowserCommandController::IsReserve
   if (window()->IsFullscreen() && command_id == IDC_FULLSCREEN)
     return true;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // If this key was registered by the user as a content editing hotkey, then
   // it is not reserved.
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
@@ -405,7 +405,7 @@ void BrowserCommandController::ExecuteCo
       break;
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     case IDC_USE_SYSTEM_TITLE_BAR: {
       PrefService* prefs = browser_->profile()->GetPrefs();
       prefs->SetBoolean(prefs::kUseCustomChromeFrame,
@@ -765,7 +765,7 @@ void BrowserCommandController::InitComma
   command_updater_.UpdateCommandEnabled(IDC_VISIT_DESKTOP_OF_LRU_USER_2, true);
   command_updater_.UpdateCommandEnabled(IDC_VISIT_DESKTOP_OF_LRU_USER_3, true);
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   command_updater_.UpdateCommandEnabled(IDC_USE_SYSTEM_TITLE_BAR, true);
 #endif
 
