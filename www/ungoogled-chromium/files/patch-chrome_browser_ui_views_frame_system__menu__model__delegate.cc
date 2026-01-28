--- chrome/browser/ui/views/frame/system_menu_model_delegate.cc.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/ui/views/frame/system_menu_model_delegate.cc
@@ -24,7 +24,7 @@
 #include "chromeos/ui/frame/desks/move_to_desks_menu_model.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/common/pref_names.h"
 #endif
 
@@ -41,7 +41,7 @@ SystemMenuModelDelegate::SystemMenuModelDelegate(
 SystemMenuModelDelegate::~SystemMenuModelDelegate() = default;
 
 bool SystemMenuModelDelegate::IsCommandIdChecked(int command_id) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_id == IDC_USE_SYSTEM_TITLE_BAR) {
     PrefService* prefs = browser_->profile()->GetPrefs();
     return !prefs->GetBoolean(prefs::kUseCustomChromeFrame);
@@ -67,7 +67,7 @@ bool SystemMenuModelDelegate::IsCommandIdEnabled(int c
 }
 
 bool SystemMenuModelDelegate::IsCommandIdVisible(int command_id) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_maximized = browser_->window()->IsMaximized();
   switch (command_id) {
     case IDC_MAXIMIZE_WINDOW:
