--- ui/views/bubble/bubble_dialog_delegate_view.cc.orig	2020-11-13 06:37:06 UTC
+++ ui/views/bubble/bubble_dialog_delegate_view.cc
@@ -319,7 +319,7 @@ Widget* BubbleDialogDelegate::CreateBubble(
   bubble_delegate->SetAnchorView(bubble_delegate->GetAnchorView());
   Widget* bubble_widget = CreateBubbleWidget(bubble_delegate);
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_APPLE)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_APPLE) || defined(OS_BSD)
   // Linux clips bubble windows that extend outside their parent window bounds.
   // Mac never adjusts.
   bubble_delegate->set_adjust_if_offscreen(false);
