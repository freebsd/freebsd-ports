--- chrome/browser/ui/toolbar/wrench_menu_model.cc.orig	2015-04-14 18:31:21.000000000 -0400
+++ chrome/browser/ui/toolbar/wrench_menu_model.cc	2015-04-28 09:58:56.258305000 -0400
@@ -762,7 +762,7 @@
 #endif
     case IDC_UPGRADE_DIALOG:
       return UpgradeDetector::GetInstance()->notify_upgrade();
-#if !defined(OS_LINUX) || defined(USE_AURA)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(USE_AURA)
     case IDC_BOOKMARK_PAGE:
       return !chrome::ShouldRemoveBookmarkThisPageUI(browser_->profile());
     case IDC_BOOKMARK_ALL_TABS:
