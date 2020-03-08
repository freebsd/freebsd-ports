--- chrome/browser/ui/views/frame/opaque_browser_frame_view.cc.orig	2020-03-03 18:53:52 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.cc
@@ -48,7 +48,7 @@
 #include "ui/views/window/vector_icons/vector_icons.h"
 #include "ui/views/window/window_shape.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/views/controls/menu/menu_runner.h"
 #endif
 
@@ -352,7 +352,7 @@ void OpaqueBrowserFrameView::ButtonPressed(views::Butt
   } else if (sender == close_button_) {
     frame()->CloseWithReason(views::Widget::ClosedReason::kCloseButtonClicked);
   } else if (sender == window_icon_) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // TODO(pbos): Figure out / document why this is Linux only. This needs a
     // comment.
     views::MenuRunner menu_runner(frame()->GetSystemMenuModel(),
@@ -481,7 +481,7 @@ bool OpaqueBrowserFrameView::EverHasVisibleBackgroundT
 
 OpaqueBrowserFrameView::FrameButtonStyle
 OpaqueBrowserFrameView::GetFrameButtonStyle() const {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return FrameButtonStyle::kMdButton;
 #else
   return FrameButtonStyle::kImageButton;
