--- ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc.orig	2026-11-19 12:25:27 UTC
+++ ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc
@@ -259,7 +259,7 @@ DragOperation DesktopDragDropClientOzone::StartDragAnd
   return selected_operation_;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopDragDropClientOzone::UpdateDragImage(const gfx::ImageSkia& image,
                                                  const gfx::Vector2d& offset) {
   DCHECK(drag_handler_);
