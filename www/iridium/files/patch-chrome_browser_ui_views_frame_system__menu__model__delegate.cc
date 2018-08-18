--- chrome/browser/ui/views/frame/system_menu_model_delegate.cc.orig	2017-06-05 19:03:03 UTC
+++ chrome/browser/ui/views/frame/system_menu_model_delegate.cc
@@ -13,7 +13,7 @@
 #include "components/sessions/core/tab_restore_service.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "chrome/common/pref_names.h"
 #include "components/prefs/pref_service.h"
 #endif
@@ -29,7 +29,7 @@ SystemMenuModelDelegate::~SystemMenuModelDelegate() {
 }
 
 bool SystemMenuModelDelegate::IsCommandIdChecked(int command_id) const {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (command_id == IDC_USE_SYSTEM_TITLE_BAR) {
     PrefService* prefs = browser_->profile()->GetPrefs();
     return !prefs->GetBoolean(prefs::kUseCustomChromeFrame);
