--- chrome/browser/ui/views/panels/panel_frame_view.cc.orig	2015-04-28 09:42:09.840501000 -0400
+++ chrome/browser/ui/views/panels/panel_frame_view.cc	2015-04-28 09:42:33.023800000 -0400
@@ -581,7 +581,7 @@
 }
 
 bool PanelFrameView::OnMouseDragged(const ui::MouseEvent& event) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Converting the mouse location to screen coordinates returns an incorrect
   // location while the panel is moving. See crbug.com/353393 for more details.
   // TODO(pkotwicz): Fix conversion to screen coordinates
