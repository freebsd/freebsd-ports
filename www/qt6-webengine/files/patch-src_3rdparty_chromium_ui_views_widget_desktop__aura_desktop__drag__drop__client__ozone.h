--- src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.h.orig	2023-01-11 09:17:16 UTC
+++ src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.h
@@ -66,7 +66,7 @@ class VIEWS_EXPORT DesktopDragDropClientOzone
     // The offset of |drag_widget_| relative to the mouse position.
     gfx::Vector2d offset;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // The last received drag location.  The drag widget is moved asynchronously
     // so its position is updated when the UI thread has time for that.  When
     // the first change to the location happens, a call to UpdateDragWidget()
@@ -87,7 +87,7 @@ class VIEWS_EXPORT DesktopDragDropClientOzone
       const gfx::Point& root_location,
       int allowed_operations,
       ui::mojom::DragEventSource source) override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void UpdateDragImage(const gfx::ImageSkia& image,
                        const gfx::Vector2d& offset) override;
 #endif
