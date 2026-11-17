--- src/chrome/browser/extensions/api/tabs/tabs_api.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/extensions/api/tabs/tabs_api.cc
@@ -1407,7 +1407,7 @@ ExtensionFunction::ResponseValue Windows
 // created as minimized.
 // TODO(crbug.com/40254339): Remove this workaround when linux is fixed.
 // TODO(crbug.com/40254339): Find a fix for wayland as well.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
   if (BrowserInitState::From(new_window)->initial_show_state() ==
       ui::mojom::WindowShowState::kMinimized) {
     new_window->GetWindow()->Minimize();
