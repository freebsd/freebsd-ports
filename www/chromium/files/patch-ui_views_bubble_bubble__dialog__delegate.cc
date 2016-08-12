--- ui/views/bubble/bubble_dialog_delegate.cc.orig	2016-08-03 16:59:43.426393000 -0400
+++ ui/views/bubble/bubble_dialog_delegate.cc	2016-08-03 17:00:10.585958000 -0400
@@ -72,7 +72,7 @@
   // the parent frame and let DWM handle compositing.  If not, then we don't
   // want to allow the bubble to extend the frame because it will be clipped.
   bubble_delegate->set_adjust_if_offscreen(ui::win::IsAeroGlassEnabled());
-#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
   // Linux clips bubble windows that extend outside their parent window bounds.
   // Mac never adjusts.
   bubble_delegate->set_adjust_if_offscreen(false);
