--- ui/views/bubble/bubble_dialog_delegate.cc.orig	2017-04-19 19:06:54 UTC
+++ ui/views/bubble/bubble_dialog_delegate.cc
@@ -76,7 +76,7 @@ Widget* BubbleDialogDelegateView::Create
   // the parent frame and let DWM handle compositing.  If not, then we don't
   // want to allow the bubble to extend the frame because it will be clipped.
   bubble_delegate->set_adjust_if_offscreen(ui::win::IsAeroGlassEnabled());
-#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
   // Linux clips bubble windows that extend outside their parent window bounds.
   // Mac never adjusts.
   bubble_delegate->set_adjust_if_offscreen(false);
