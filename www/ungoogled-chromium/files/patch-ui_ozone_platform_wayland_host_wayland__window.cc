--- ui/ozone/platform/wayland/host/wayland_window.cc.orig	2024-08-26 14:40:28 UTC
+++ ui/ozone/platform/wayland/host/wayland_window.cc
@@ -317,7 +317,7 @@ void WaylandWindow::OnPointerFocusChanged(bool focused
   // Whenever the window gets the pointer focus back, the cursor shape must be
   // updated. Otherwise, it is invalidated upon wl_pointer::leave and is not
   // restored by the Wayland compositor.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (focused && async_cursor_) {
     async_cursor_->AddCursorLoadedCallback(base::BindOnce(
         &WaylandWindow::OnCursorLoaded, AsWeakPtr(), async_cursor_));
@@ -575,7 +575,7 @@ bool WaylandWindow::ShouldUseNativeFrame() const {
 void WaylandWindow::SetCursor(scoped_refptr<PlatformCursor> platform_cursor) {
   DCHECK(platform_cursor);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto async_cursor = WaylandAsyncCursor::FromPlatformCursor(platform_cursor);
 
   if (async_cursor_ == async_cursor) {
@@ -786,7 +786,7 @@ std::string WaylandWindow::WindowStates::ToString() co
   } else {
     base::TrimString(states, " ", &states);
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   states += "; tiled_edges: ";
   std::string tiled = "";
   if (tiled_edges.left) {
@@ -1274,12 +1274,12 @@ void WaylandWindow::UpdateCursorShape(scoped_refptr<Bi
         cursor->bitmaps(), hotspot_in_dips,
         std::ceil(cursor->cursor_image_scale_factor()));
   }
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   cursor_ = cursor;
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WaylandWindow::OnCursorLoaded(scoped_refptr<WaylandAsyncCursor> cursor,
                                    scoped_refptr<BitmapCursor> bitmap_cursor) {
   if (HasPointerFocus() && async_cursor_ == cursor && bitmap_cursor) {
