--- chrome/browser/ui/views/frame/opaque_browser_frame_view.cc.orig	2021-09-24 04:26:00 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.cc
@@ -53,7 +53,7 @@
 #include "ui/views/window/vector_icons/vector_icons.h"
 #include "ui/views/window/window_shape.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/views/controls/menu/menu_runner.h"
 #endif
 
@@ -516,7 +516,7 @@ OpaqueBrowserFrameView::FrameButtonStyle
 OpaqueBrowserFrameView::GetFrameButtonStyle() const {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return FrameButtonStyle::kMdButton;
 #else
   return FrameButtonStyle::kImageButton;
@@ -726,7 +726,7 @@ gfx::Rect OpaqueBrowserFrameView::GetIconBounds() cons
 }
 
 void OpaqueBrowserFrameView::WindowIconPressed() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // TODO(pbos): Figure out / document why this is Linux only. This needs a
   // comment.
   views::MenuRunner menu_runner(frame()->GetSystemMenuModel(),
