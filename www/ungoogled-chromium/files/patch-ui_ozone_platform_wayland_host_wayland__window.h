--- ui/ozone/platform/wayland/host/wayland_window.h.orig	2025-02-20 09:59:21 UTC
+++ ui/ozone/platform/wayland/host/wayland_window.h
@@ -40,7 +40,7 @@
 #include "ui/platform_window/platform_window_init_properties.h"
 #include "ui/platform_window/wm/wm_drag_handler.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/platform/wayland/host/wayland_async_cursor.h"
 #endif
 
@@ -259,7 +259,7 @@ class WaylandWindow : public PlatformWindow,
     bool is_activated = false;
     bool is_minimized = false;
     bool is_suspended = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     WindowTiledEdges tiled_edges;
 #endif
 
@@ -533,7 +533,7 @@ class WaylandWindow : public PlatformWindow,
 
   void UpdateCursorShape(scoped_refptr<BitmapCursor> cursor);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnCursorLoaded(scoped_refptr<WaylandAsyncCursor> cursor,
                       scoped_refptr<BitmapCursor> bitmap_cursor);
 #endif
@@ -603,7 +603,7 @@ class WaylandWindow : public PlatformWindow,
   // the subsurface arrangement are played back by WaylandFrameManager.
   base::LinkedList<WaylandSubsurface> subsurface_stack_committed_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The current asynchronously loaded cursor (Linux specific).
   scoped_refptr<WaylandAsyncCursor> async_cursor_;
 #else
