--- chrome/browser/ui/views/frame/opaque_browser_frame_view.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.cc
@@ -53,7 +53,7 @@
 #include "ui/views/window/vector_icons/vector_icons.h"
 #include "ui/views/window/window_shape.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/views/controls/menu/menu_runner.h"
 #endif
 
@@ -541,7 +541,7 @@ OpaqueBrowserFrameView::FrameButtonStyle
 OpaqueBrowserFrameView::GetFrameButtonStyle() const {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return FrameButtonStyle::kMdButton;
 #else
   return FrameButtonStyle::kImageButton;
@@ -751,7 +751,7 @@ gfx::Rect OpaqueBrowserFrameView::GetIconBounds() cons
 }
 
 void OpaqueBrowserFrameView::WindowIconPressed() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Chrome OS doesn't show the window icon, and Windows handles this on its own
   // due to the hit test being HTSYSMENU.
   menu_runner_ = std::make_unique<views::MenuRunner>(
