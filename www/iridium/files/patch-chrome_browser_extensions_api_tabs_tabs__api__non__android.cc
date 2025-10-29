--- chrome/browser/extensions/api/tabs/tabs_api_non_android.cc.orig	2025-10-28 14:29:43 UTC
+++ chrome/browser/extensions/api/tabs/tabs_api_non_android.cc
@@ -663,7 +663,7 @@ ExtensionFunction::ResponseAction WindowsCreateFunctio
 // created as minimized.
 // TODO(crbug.com/40254339): Remove this workaround when linux is fixed.
 // TODO(crbug.com/40254339): Find a fix for wayland as well.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   if (new_window->initial_show_state() ==
       ui::mojom::WindowShowState::kMinimized) {
     new_window->window()->Minimize();
