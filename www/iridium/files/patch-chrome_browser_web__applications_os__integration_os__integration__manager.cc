--- chrome/browser/web_applications/os_integration/os_integration_manager.cc.orig	2024-08-01 05:47:53 UTC
+++ chrome/browser/web_applications/os_integration/os_integration_manager.cc
@@ -651,7 +651,7 @@ std::unique_ptr<ShortcutInfo> OsIntegrationManager::Bu
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::vector<WebAppShortcutsMenuItemInfo>& shortcuts_menu_item_infos =
       app->shortcuts_menu_item_infos();
   DCHECK_LE(shortcuts_menu_item_infos.size(), kMaxApplicationDockMenuItems);
