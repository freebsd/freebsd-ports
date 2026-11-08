--- chrome/browser/ui/views/omnibox/omnibox_popup_full_presenter.cc.orig	2026-10-22 09:04:01 UTC
+++ chrome/browser/ui/views/omnibox/omnibox_popup_full_presenter.cc
@@ -51,7 +51,7 @@
 #include "ui/views/view_class_properties.h"
 #include "ui/views/view_utils.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/aura/window.h"
 #include "ui/aura/window_tree_host.h"
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_platform.h"
@@ -81,7 +81,7 @@ bool IsBrowserWindowActive(views::Widget* browser_widg
   if (!browser_widget) {
     return false;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (aura::Window* native_window = browser_widget->GetNativeWindow();
       native_window && native_window->GetHost()) {
     if (auto* host = views::DesktopWindowTreeHostPlatform::GetHostForWidget(
