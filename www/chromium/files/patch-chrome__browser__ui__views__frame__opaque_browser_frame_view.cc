--- chrome/browser/ui/views/frame/opaque_browser_frame_view.cc.orig	2014-10-10 09:15:30 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.cc
@@ -52,7 +52,7 @@
 #include "ui/views/window/frame_background.h"
 #include "ui/views/window/window_shape.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/views/controls/menu/menu_runner.h"
 #endif
 
@@ -77,7 +77,7 @@
 // The icon never shrinks below 16 px on a side.
 const int kIconMinimumSize = 16;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 // The number of pixels to move the frame background image upwards when using
 // the GTK+ theme and the titlebar is condensed.
 const int kGTKThemeCondensedFrameTopInset = 15;
@@ -318,7 +318,7 @@
 
 void OpaqueBrowserFrameView::OnMenuButtonClicked(views::View* source,
                                                  const gfx::Point& point) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX)  || defined(OS_BSD)
   views::MenuRunner menu_runner(frame()->GetSystemMenuModel(),
                                 views::MenuRunner::HAS_MNEMONICS);
   ignore_result(menu_runner.RunMenuAt(browser_view()->GetWidget(),
@@ -571,7 +571,7 @@
 }
 
 bool OpaqueBrowserFrameView::ShouldShowWindowTitleBar() const {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS)  || defined(OS_BSD)
   // Do not show the custom title bar if the system title bar option is enabled.
   if (!frame()->UseCustomFrame())
     return false;
@@ -616,7 +616,7 @@
   frame_background_->set_theme_image(GetFrameImage());
   frame_background_->set_theme_overlay_image(GetFrameOverlayImage());
   frame_background_->set_top_area_height(GetTopAreaHeight());
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   // The window manager typically shows a gradient in the native title bar (when
   // the system title bar pref is set, or when maximized on Ubuntu). Hide the
   // gradient in the tab strip (by shifting it up vertically) to avoid a
