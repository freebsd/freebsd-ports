--- chrome/browser/ui/toolbar/wrench_menu_model.cc.orig	2015-07-15 16:29:58.000000000 -0400
+++ chrome/browser/ui/toolbar/wrench_menu_model.cc	2015-07-21 21:50:51.697458000 -0400
@@ -796,7 +796,7 @@
     case IDC_UPGRADE_DIALOG:
       return browser_defaults::kShowUpgradeMenuItem &&
           UpgradeDetector::GetInstance()->notify_upgrade();
-#if !defined(OS_LINUX) || defined(USE_AURA)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(USE_AURA)
     case IDC_BOOKMARK_PAGE:
       return !chrome::ShouldRemoveBookmarkThisPageUI(browser_->profile());
     case IDC_BOOKMARK_ALL_TABS:
