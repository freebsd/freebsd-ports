--- chrome/browser/ui/views/frame/opaque_browser_frame_view.cc.orig	2016-01-21 15:44:16.454185203 +0100
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.cc	2016-01-21 15:50:24.719159940 +0100
@@ -55,7 +55,7 @@
 #include "chrome/browser/ui/views/profiles/supervised_user_avatar_label.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/views/controls/menu/menu_runner.h"
 #endif
 
@@ -336,7 +336,7 @@
 
 void OpaqueBrowserFrameView::OnMenuButtonClicked(views::View* source,
                                                  const gfx::Point& point) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   views::MenuRunner menu_runner(frame()->GetSystemMenuModel(),
                                 views::MenuRunner::HAS_MNEMONICS);
   ignore_result(menu_runner.RunMenuAt(browser_view()->GetWidget(),
