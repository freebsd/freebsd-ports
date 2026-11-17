--- src/chrome/browser/web_applications/os_integration/os_integration_manager.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/web_applications/os_integration/os_integration_manager.cc
@@ -687,7 +687,7 @@ std::unique_ptr<ShortcutInfo> OsIntegrat
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::vector<WebAppShortcutsMenuItemInfo>& shortcuts_menu_item_infos =
       app->shortcuts_menu_item_infos();
   DCHECK_LE(shortcuts_menu_item_infos.size(), kMaxApplicationDockMenuItems);
