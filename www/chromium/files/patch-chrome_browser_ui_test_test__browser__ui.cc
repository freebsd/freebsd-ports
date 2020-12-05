--- chrome/browser/ui/test/test_browser_ui.cc.orig	2020-11-13 06:36:38 UTC
+++ chrome/browser/ui/test/test_browser_ui.cc
@@ -10,7 +10,7 @@
 #include "build/build_config.h"
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/test/pixel/browser_skia_gold_pixel_diff.h"
 #include "ui/base/test/skia_gold_matching_algorithm.h"
 #include "ui/compositor/test/draw_waiter_for_test.h"
@@ -32,7 +32,7 @@ std::string NameFromTestCase() {
 }  // namespace
 
 TestBrowserUi::TestBrowserUi() {
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Default to fuzzy diff. The magic number is chosen based on
   // past experiments.
   SetPixelMatchAlgorithm(
@@ -43,7 +43,7 @@ TestBrowserUi::TestBrowserUi() {
 TestBrowserUi::~TestBrowserUi() = default;
 
 // TODO(https://crbug.com/958242) support Mac for pixel tests.
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 bool TestBrowserUi::VerifyPixelUi(views::Widget* widget,
                                   const std::string& screenshot_prefix,
                                   const std::string& screenshot_name) {
