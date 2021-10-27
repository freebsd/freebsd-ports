--- chrome/browser/ui/test/test_browser_ui.h.orig	2021-09-24 18:31:01 UTC
+++ chrome/browser/ui/test/test_browser_ui.h
@@ -95,7 +95,7 @@ class TestBrowserUi {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   // Can be called by VerifyUi() to ensure pixel correctness.
   bool VerifyPixelUi(views::Widget* widget,
                      const std::string& screenshot_prefix,
@@ -132,7 +132,7 @@ class TestBrowserUi {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   std::unique_ptr<ui::test::SkiaGoldMatchingAlgorithm> algorithm_;
 #endif
 
