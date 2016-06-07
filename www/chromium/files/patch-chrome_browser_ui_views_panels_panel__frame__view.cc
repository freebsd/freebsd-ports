--- chrome/browser/ui/views/panels/panel_frame_view.cc.orig	2016-05-11 19:02:16 UTC
+++ chrome/browser/ui/views/panels/panel_frame_view.cc
@@ -589,7 +589,7 @@ bool PanelFrameView::OnMousePressed(cons
 }
 
 bool PanelFrameView::OnMouseDragged(const ui::MouseEvent& event) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Converting the mouse location to screen coordinates returns an incorrect
   // location while the panel is moving. See crbug.com/353393 for more details.
   // TODO(pkotwicz): Fix conversion to screen coordinates
