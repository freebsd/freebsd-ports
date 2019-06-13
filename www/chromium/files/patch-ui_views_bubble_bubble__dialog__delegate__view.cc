--- ui/views/bubble/bubble_dialog_delegate_view.cc.orig	2019-06-04 18:55:50 UTC
+++ ui/views/bubble/bubble_dialog_delegate_view.cc
@@ -135,7 +135,7 @@ Widget* BubbleDialogDelegateView::CreateBubble(
   bubble_delegate->SetAnchorView(bubble_delegate->GetAnchorView());
   Widget* bubble_widget = CreateBubbleWidget(bubble_delegate);
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
   // Linux clips bubble windows that extend outside their parent window bounds.
   // Mac never adjusts.
   bubble_delegate->set_adjust_if_offscreen(false);
