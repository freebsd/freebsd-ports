--- chrome/browser/renderer_context_menu/render_view_context_menu.h.orig	2021-09-24 18:28:06 UTC
+++ chrome/browser/renderer_context_menu/render_view_context_menu.h
@@ -32,7 +32,7 @@
 #include "ui/base/window_open_disposition.h"
 #include "ui/gfx/geometry/vector2d.h"
 
-#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/lens/region_search/lens_region_search_controller.h"
 #endif
 
@@ -359,7 +359,7 @@ class RenderViewContextMenu : public RenderViewContext
   // The type of system app (if any) associated with the WebContents we're in.
   absl::optional<web_app::SystemAppType> system_app_type_;
 
-#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
   // Controller for Lens Region Search feature. This controller will be
   // destroyed as soon as the RenderViewContextMenu object is destroyed. The
   // RenderViewContextMenu is reset every time it is shown, but persists between
