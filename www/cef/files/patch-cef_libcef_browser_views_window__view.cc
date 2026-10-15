--- cef/libcef/browser/views/window_view.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/views/window_view.cc
@@ -9,7 +9,7 @@
 
 #include "base/memory/raw_ptr.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ozone_buildflags.h"
 #if BUILDFLAG(SUPPORTS_OZONE_X11)
 // Include first due to redefinition of x11::EventMask.
@@ -29,7 +29,7 @@
 #include "ui/views/widget/widget.h"
 #include "ui/views/window/native_frame_view.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(SUPPORTS_OZONE_X11)
 #include "ui/gfx/x/atom_cache.h"
 #include "ui/linux/linux_ui_delegate.h"
@@ -457,7 +457,7 @@ class CefWindowWidgetDelegate : public v
   }
 
   bool MaybeGetMinimumSize(gfx::Size* size) const override {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Resize is disabled on Linux by returning the preferred size as the
     // min/max size.
     if (!CanResize()) {
@@ -469,7 +469,7 @@ class CefWindowWidgetDelegate : public v
   }
 
   bool MaybeGetMaximumSize(gfx::Size* size) const override {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Resize is disabled on Linux by returning the preferred size as the
     // min/max size.
     if (!CanResize()) {
@@ -547,7 +547,7 @@ void CefWindowView::CreateWidget(gfx::Ac
     auto bounds = cef_delegate()->GetInitialBounds(cef_window);
     params.bounds = gfx::Rect(bounds.x, bounds.y, bounds.width, bounds.height);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     CefLinuxWindowProperties linux_props;
     if (cef_delegate()->GetLinuxWindowProperties(cef_window, linux_props)) {
       params.wayland_app_id = CefString(&linux_props.wayland_app_id);
@@ -623,7 +623,7 @@ void CefWindowView::CreateWidget(gfx::Ac
           // variant with browser windows to get proper focus and shutdown
           // behavior.
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
           // SetModalType doesn't work on Linux (no implementation in
           // DesktopWindowTreeHostLinux::InitModalType). See the X11-specific
           // implementation below that may work with some window managers.
@@ -677,7 +677,7 @@ void CefWindowView::CreateWidget(gfx::Ac
 
   cef_widget->Initialized();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(SUPPORTS_OZONE_X11)
   auto x11window = static_cast<x11::Window>(view_util::GetWindowHandle(widget));
   CHECK(x11window != x11::Window::None);
@@ -770,7 +770,7 @@ void CefWindowView::WindowClosing() {
     overlay_host->Close();
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(SUPPORTS_OZONE_X11)
   if (host_widget()) {
     auto parent = static_cast<gfx::AcceleratedWidget>(
