--- chrome/browser/ui/views/frame/system_menu_model_delegate.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/views/frame/system_menu_model_delegate.cc
@@ -30,7 +30,7 @@
 #include "chromeos/ui/frame/desks/move_to_desks_menu_model.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/common/pref_names.h"
 #endif
 
@@ -49,7 +49,7 @@ SystemMenuModelDelegate::SystemMenuModelDelegate(
 SystemMenuModelDelegate::~SystemMenuModelDelegate() = default;
 
 bool SystemMenuModelDelegate::IsCommandIdChecked(int command_id) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_id == IDC_USE_SYSTEM_TITLE_BAR) {
     PrefService* prefs = browser_->GetProfile()->GetPrefs();
     return !prefs->GetBoolean(prefs::kUseCustomChromeFrame);
@@ -93,7 +93,7 @@ bool SystemMenuModelDelegate::IsCommandIdEnabled(int c
 }
 
 bool SystemMenuModelDelegate::IsCommandIdVisible(int command_id) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_maximized = browser_->GetWindow()->IsMaximized();
   switch (command_id) {
     case IDC_MAXIMIZE_WINDOW:
