--- src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc.orig	2023-01-11 09:17:16 UTC
+++ src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc
@@ -194,7 +194,7 @@ DragOperation DesktopDragDropClientOzone::StartDragAnd
   return drag_operation_;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopDragDropClientOzone::UpdateDragImage(const gfx::ImageSkia& image,
                                                  const gfx::Vector2d& offset) {
   DCHECK(drag_handler_);
