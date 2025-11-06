--- chrome/browser/web_applications/os_integration/os_integration_manager.cc.orig	2025-11-06 10:11:34 UTC
+++ chrome/browser/web_applications/os_integration/os_integration_manager.cc
@@ -665,7 +665,7 @@ std::unique_ptr<ShortcutInfo> OsIntegrationManager::Bu
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::vector<WebAppShortcutsMenuItemInfo>& shortcuts_menu_item_infos =
       app->shortcuts_menu_item_infos();
   DCHECK_LE(shortcuts_menu_item_infos.size(), kMaxApplicationDockMenuItems);
