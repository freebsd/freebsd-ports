--- chrome/browser/ui/views/frame/opaque_browser_frame_view.cc.orig	2015-04-18 23:48:58.000000000 +0200
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.cc	2015-04-18 23:53:50.000000000 +0200
@@ -54,7 +54,7 @@
 #include "chrome/browser/ui/views/profiles/supervised_user_avatar_label.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/views/controls/menu/menu_runner.h"
 #endif
 
@@ -79,7 +79,7 @@
 // The icon never shrinks below 16 px on a side.
 const int kIconMinimumSize = 16;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 // The number of pixels to move the frame background image upwards when using
 // the GTK+ theme and the titlebar is condensed.
 const int kGTKThemeCondensedFrameTopInset = 15;
@@ -341,7 +341,7 @@
 
 void OpaqueBrowserFrameView::OnMenuButtonClicked(views::View* source,
                                                  const gfx::Point& point) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   views::MenuRunner menu_runner(frame()->GetSystemMenuModel(),
                                 views::MenuRunner::HAS_MNEMONICS);
   ignore_result(menu_runner.RunMenuAt(browser_view()->GetWidget(),
@@ -637,7 +637,7 @@
   frame_background_->set_theme_image(GetFrameImage());
   frame_background_->set_theme_overlay_image(GetFrameOverlayImage());
   frame_background_->set_top_area_height(GetTopAreaHeight());
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   // The window manager typically shows a gradient in the native title bar (when
   // the system title bar pref is set, or when maximized on Ubuntu). Hide the
   // gradient in the tab strip (by shifting it up vertically) to avoid a
