--- chrome/browser/web_applications/web_app_shortcut_manager.cc.orig	2021-12-16 14:52:50 UTC
+++ chrome/browser/web_applications/web_app_shortcut_manager.cc
@@ -35,10 +35,10 @@ namespace web_app {
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Aligns with other platform implementations that only support 10 items.
 constexpr int kMaxApplicationDockMenuItems = 10;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 // UMA metric name for shortcuts creation result.
 constexpr const char* kCreationResultMetric =
@@ -383,7 +383,7 @@ std::unique_ptr<ShortcutInfo> WebAppShortcutManager::B
     }
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const std::vector<WebApplicationShortcutsMenuItemInfo>&
       shortcuts_menu_item_infos = app->shortcuts_menu_item_infos();
   int num_entries = std::min(static_cast<int>(shortcuts_menu_item_infos.size()),
@@ -401,7 +401,7 @@ std::unique_ptr<ShortcutInfo> WebAppShortcutManager::B
           shortcuts_menu_item_info.url);
     }
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   return shortcut_info;
 }
