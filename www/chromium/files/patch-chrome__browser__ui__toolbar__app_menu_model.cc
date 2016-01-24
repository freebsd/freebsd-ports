--- chrome/browser/ui/toolbar/app_menu_model.cc.orig	2016-01-21 14:37:58.792459231 +0100
+++ chrome/browser/ui/toolbar/app_menu_model.cc	2016-01-21 14:39:05.304456038 +0100
@@ -779,7 +779,7 @@
     case IDC_UPGRADE_DIALOG:
       return browser_defaults::kShowUpgradeMenuItem &&
           UpgradeDetector::GetInstance()->notify_upgrade();
-#if !defined(OS_LINUX) || defined(USE_AURA)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(USE_AURA)
     case IDC_BOOKMARK_PAGE:
       return !chrome::ShouldRemoveBookmarkThisPageUI(browser_->profile());
     case IDC_BOOKMARK_ALL_TABS:
