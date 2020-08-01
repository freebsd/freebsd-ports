--- chrome/browser/ui/test/test_browser_ui.cc.orig	2020-07-13 09:23:57 UTC
+++ chrome/browser/ui/test/test_browser_ui.cc
@@ -10,7 +10,7 @@
 #include "build/build_config.h"
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/test/pixel/browser_skia_gold_pixel_diff.h"
 #include "ui/compositor/test/draw_waiter_for_test.h"
 #include "ui/views/widget/widget.h"
@@ -37,7 +37,7 @@ bool TestBrowserUi::VerifyPixelUi(views::Widget* widge
                                   const std::string& screenshot_prefix,
                                   const std::string& screenshot_name) {
 // TODO(https://crbug.com/958242) support Mac for pixel tests.
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (!base::CommandLine::ForCurrentProcess()->HasSwitch(
           "browser-ui-tests-verify-pixels"))
     return true;
