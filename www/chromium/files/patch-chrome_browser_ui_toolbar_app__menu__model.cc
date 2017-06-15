--- chrome/browser/ui/toolbar/app_menu_model.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/toolbar/app_menu_model.cc
@@ -631,7 +631,7 @@ bool AppMenuModel::IsCommandIdVisible(in
     case IDC_UPGRADE_DIALOG:
       return browser_defaults::kShowUpgradeMenuItem &&
           UpgradeDetector::GetInstance()->notify_upgrade();
-#if !defined(OS_LINUX) || defined(USE_AURA)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(USE_AURA)
     case IDC_BOOKMARK_PAGE:
       return !chrome::ShouldRemoveBookmarkThisPageUI(browser_->profile());
     case IDC_BOOKMARK_ALL_TABS:
