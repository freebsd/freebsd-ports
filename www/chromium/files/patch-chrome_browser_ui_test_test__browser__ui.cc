--- chrome/browser/ui/test/test_browser_ui.cc.orig	2021-12-14 11:44:59 UTC
+++ chrome/browser/ui/test/test_browser_ui.cc
@@ -16,7 +16,7 @@
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 #include "chrome/test/pixel/browser_skia_gold_pixel_diff.h"
 #include "ui/base/test/skia_gold_matching_algorithm.h"
 #include "ui/compositor/test/draw_waiter_for_test.h"
@@ -37,7 +37,7 @@ std::string NameFromTestCase() {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 void InstallUIControlsAura() {
 #if defined(OS_WIN)
   ui_controls::InstallUIControlsAura(aura::test::CreateUIControlsAura(nullptr));
@@ -55,7 +55,7 @@ void InstallUIControlsAura() {
 TestBrowserUi::TestBrowserUi() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   // Default to fuzzy diff. The magic number is chosen based on
   // past experiments.
   SetPixelMatchAlgorithm(
@@ -68,7 +68,7 @@ TestBrowserUi::~TestBrowserUi() = default;
 // TODO(https://crbug.com/958242) support Mac for pixel tests.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 bool TestBrowserUi::VerifyPixelUi(views::Widget* widget,
                                   const std::string& screenshot_prefix,
                                   const std::string& screenshot_name) {
