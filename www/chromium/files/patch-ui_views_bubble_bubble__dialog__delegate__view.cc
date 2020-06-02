--- ui/views/bubble/bubble_dialog_delegate_view.cc.orig	2020-05-13 18:40:37 UTC
+++ ui/views/bubble/bubble_dialog_delegate_view.cc
@@ -171,7 +171,7 @@ Widget* BubbleDialogDelegateView::CreateBubble(
   bubble_delegate->Init();
   Widget* bubble_widget = CreateBubbleWidget(bubble_delegate);
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
   // Linux clips bubble windows that extend outside their parent window bounds.
   // Mac never adjusts.
   bubble_delegate->set_adjust_if_offscreen(false);
