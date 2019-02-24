--- chrome/browser/ui/toolbar/app_menu_model.cc.orig	2019-01-30 02:17:48.000000000 +0100
+++ chrome/browser/ui/toolbar/app_menu_model.cc	2019-01-31 23:16:29.559467000 +0100
@@ -664,7 +664,7 @@
       return app_menu_icon_controller_->GetTypeAndSeverity().type ==
              AppMenuIconController::IconType::UPGRADE_NOTIFICATION;
     }
-#if !defined(OS_LINUX) || defined(USE_AURA)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(USE_AURA)
     case IDC_BOOKMARK_PAGE:
       return !chrome::ShouldRemoveBookmarkThisPageUI(browser_->profile());
     case IDC_BOOKMARK_ALL_TABS:
