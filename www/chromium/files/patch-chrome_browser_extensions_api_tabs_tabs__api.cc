--- chrome/browser/extensions/api/tabs/tabs_api.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/extensions/api/tabs/tabs_api.cc
@@ -1187,7 +1187,7 @@ ExtensionFunction::ResponseValue WindowsCreateFunction
 // created as minimized.
 // TODO(crbug.com/40254339): Remove this workaround when linux is fixed.
 // TODO(crbug.com/40254339): Find a fix for wayland as well.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))&& BUILDFLAG(SUPPORTS_OZONE_X11)
   if (new_window->GetBrowserForMigrationOnly()->initial_show_state() ==
       ui::mojom::WindowShowState::kMinimized) {
     new_window->GetWindow()->Minimize();
