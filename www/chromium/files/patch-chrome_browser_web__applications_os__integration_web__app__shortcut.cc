--- chrome/browser/web_applications/os_integration/web_app_shortcut.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/web_applications/os_integration/web_app_shortcut.cc
@@ -228,7 +228,7 @@ std::unique_ptr<ShortcutInfo> BuildShortcutInfoWithout
 
 // TODO(crbug.com/40257107): Implement tests on Linux for using shortcuts_menu
 // actions.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::vector<WebAppShortcutsMenuItemInfo>& shortcuts_menu_item_infos =
       CreateShortcutsMenuItemInfos(state.shortcut_menus());
   DCHECK_LE(shortcuts_menu_item_infos.size(), kMaxApplicationDockMenuItems);
@@ -404,7 +404,7 @@ base::span<const int> GetDesiredIconSizesForShortcut()
 #if BUILDFLAG(IS_MAC)
   static constexpr int kDesiredIconSizesForShortcut[] = {16, 32, 128, 256, 512};
   return kDesiredIconSizesForShortcut;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Linux supports icons of any size. FreeDesktop Icon Theme Specification
   // states that "Minimally you should install a 48x48 icon in the hicolor
   // theme."
