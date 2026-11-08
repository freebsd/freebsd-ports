--- chrome/browser/extensions/api/tabs/tabs_api.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/extensions/api/tabs/tabs_api.cc
@@ -1369,7 +1369,7 @@ ExtensionFunction::ResponseValue WindowsCreateFunction
 // created as minimized.
 // TODO(crbug.com/40254339): Remove this workaround when linux is fixed.
 // TODO(crbug.com/40254339): Find a fix for wayland as well.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
   if (BrowserInitState::From(weak_window.get())->initial_show_state() ==
       ui::mojom::WindowShowState::kMinimized) {
     weak_window->GetWindow()->Minimize();
