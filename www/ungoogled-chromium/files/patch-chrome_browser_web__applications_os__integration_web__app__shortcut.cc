--- chrome/browser/web_applications/os_integration/web_app_shortcut.cc.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/web_applications/os_integration/web_app_shortcut.cc
@@ -66,7 +66,7 @@ namespace {
 
 #if BUILDFLAG(IS_MAC)
 const int kDesiredIconSizesForShortcut[] = {16, 32, 128, 256, 512};
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Linux supports icons of any size. FreeDesktop Icon Theme Specification states
 // that "Minimally you should install a 48x48 icon in the hicolor theme."
 const int kDesiredIconSizesForShortcut[] = {16, 32, 48, 128, 256, 512};
@@ -248,7 +248,7 @@ std::unique_ptr<ShortcutInfo> BuildShortcutInfoWithout
 
 // TODO(crbug.com/40257107): Implement tests on Linux for using shortcuts_menu
 // actions.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::vector<WebAppShortcutsMenuItemInfo>& shortcuts_menu_item_infos =
       CreateShortcutsMenuItemInfos(state.shortcut_menus());
   DCHECK_LE(shortcuts_menu_item_infos.size(), kMaxApplicationDockMenuItems);
