--- chrome/browser/web_applications/os_integration/os_integration_manager.cc.orig	2026-02-16 10:45:29 UTC
+++ chrome/browser/web_applications/os_integration/os_integration_manager.cc
@@ -676,7 +676,7 @@ std::unique_ptr<ShortcutInfo> OsIntegrationManager::Bu
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::vector<WebAppShortcutsMenuItemInfo>& shortcuts_menu_item_infos =
       app->shortcuts_menu_item_infos();
   DCHECK_LE(shortcuts_menu_item_infos.size(), kMaxApplicationDockMenuItems);
