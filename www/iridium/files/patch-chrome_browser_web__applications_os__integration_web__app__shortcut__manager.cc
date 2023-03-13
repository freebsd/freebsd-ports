--- chrome/browser/web_applications/os_integration/web_app_shortcut_manager.cc.orig	2023-03-13 07:33:08 UTC
+++ chrome/browser/web_applications/os_integration/web_app_shortcut_manager.cc
@@ -452,7 +452,7 @@ std::unique_ptr<ShortcutInfo> WebAppShortcutManager::B
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::vector<WebAppShortcutsMenuItemInfo>& shortcuts_menu_item_infos =
       app->shortcuts_menu_item_infos();
   DCHECK_LE(shortcuts_menu_item_infos.size(), kMaxApplicationDockMenuItems);
