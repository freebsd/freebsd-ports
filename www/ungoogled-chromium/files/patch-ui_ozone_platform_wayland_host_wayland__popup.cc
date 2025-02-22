--- ui/ozone/platform/wayland/host/wayland_popup.cc.orig	2025-02-20 09:59:21 UTC
+++ ui/ozone/platform/wayland/host/wayland_popup.cc
@@ -31,7 +31,7 @@ WaylandPopup::WaylandPopup(PlatformWindowDelegate* del
                            WaylandWindow* parent)
     : WaylandWindow(delegate, connection) {
   set_parent_window(parent);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/330384470): Whether the popup appear depends on whether
   // anchor point is outside of the parent xdg_surface. On Mutter the popup will
   // not show when outside.
