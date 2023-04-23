--- src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.h.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.h
@@ -68,7 +68,7 @@ class VIEWS_EXPORT DesktopDragDropClientOzone
     // The offset of |drag_widget_| relative to the mouse position.
     gfx::Vector2d offset;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // The last received drag location.  The drag widget is moved asynchronously
     // so its position is updated when the UI thread has time for that.  When
     // the first change to the location happens, a call to UpdateDragWidget()
