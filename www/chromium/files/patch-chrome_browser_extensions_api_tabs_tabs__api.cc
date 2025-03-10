--- chrome/browser/extensions/api/tabs/tabs_api.cc.orig	2025-02-19 07:43:18 UTC
+++ chrome/browser/extensions/api/tabs/tabs_api.cc
@@ -919,7 +919,7 @@ ExtensionFunction::ResponseAction WindowsCreateFunctio
 // created as minimized.
 // TODO(crbug.com/40254339): Remove this workaround when linux is fixed.
 // TODO(crbug.com/40254339): Find a fix for wayland as well.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   if (new_window->initial_show_state() ==
       ui::mojom::WindowShowState::kMinimized) {
     new_window->window()->Minimize();
