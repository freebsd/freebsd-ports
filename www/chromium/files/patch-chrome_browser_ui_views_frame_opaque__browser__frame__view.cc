--- chrome/browser/ui/views/frame/opaque_browser_frame_view.cc.orig	2025-12-05 10:12:50 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.cc
@@ -55,7 +55,7 @@
 #include "ui/views/window/vector_icons/vector_icons.h"
 #include "ui/views/window/window_shape.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/views/controls/menu/menu_runner.h"
 #endif
 
@@ -605,7 +605,7 @@ bool OpaqueBrowserFrameView::IsFrameCondensed() const 
 
 OpaqueBrowserFrameView::FrameButtonStyle
 OpaqueBrowserFrameView::GetFrameButtonStyle() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameButtonStyle::kMdButton;
 #else
   return FrameButtonStyle::kImageButton;
@@ -624,7 +624,7 @@ bool OpaqueBrowserFrameView::ShouldDrawRestoredFrameSh
   return false;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OpaqueBrowserFrameView::IsTiled() const {
   return browser_widget()->tiled();
 }
@@ -856,7 +856,7 @@ gfx::Rect OpaqueBrowserFrameView::GetIconBounds() cons
 }
 
 void OpaqueBrowserFrameView::WindowIconPressed() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Chrome OS doesn't show the window icon, and Windows handles this on its own
   // due to the hit test being HTSYSMENU.
   menu_runner_ = std::make_unique<views::MenuRunner>(
