--- ui/views/bubble/bubble_dialog_delegate_view.cc.orig	2018-12-15 21:04:16.740410000 +0100
+++ ui/views/bubble/bubble_dialog_delegate_view.cc	2018-12-15 21:05:12.625861000 +0100
@@ -114,7 +114,7 @@
   bubble_delegate->SetAnchorView(bubble_delegate->GetAnchorView());
   Widget* bubble_widget = CreateBubbleWidget(bubble_delegate);
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
   // Linux clips bubble windows that extend outside their parent window bounds.
   // Mac never adjusts.
   bubble_delegate->set_adjust_if_offscreen(false);
