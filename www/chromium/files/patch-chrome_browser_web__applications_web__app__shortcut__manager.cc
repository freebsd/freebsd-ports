--- chrome/browser/web_applications/web_app_shortcut_manager.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/web_applications/web_app_shortcut_manager.cc
@@ -35,7 +35,7 @@ namespace web_app {
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Aligns with other platform implementations that only support 10 items.
 constexpr int kMaxApplicationDockMenuItems = 10;
 #endif  // defined(OS_LINUX)
@@ -382,7 +382,7 @@ std::unique_ptr<ShortcutInfo> WebAppShortcutManager::B
     }
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const std::vector<WebAppShortcutsMenuItemInfo>& shortcuts_menu_item_infos =
       app->shortcuts_menu_item_infos();
   int num_entries = std::min(static_cast<int>(shortcuts_menu_item_infos.size()),
