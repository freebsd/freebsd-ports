--- chrome/browser/ui/test/test_browser_ui.h.orig	2021-12-14 11:44:59 UTC
+++ chrome/browser/ui/test/test_browser_ui.h
@@ -100,7 +100,7 @@ class TestBrowserUi {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   // Can be called by VerifyUi() to ensure pixel correctness.
   bool VerifyPixelUi(views::Widget* widget,
                      const std::string& screenshot_prefix,
@@ -137,7 +137,7 @@ class TestBrowserUi {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   std::unique_ptr<ui::test::SkiaGoldMatchingAlgorithm> algorithm_;
 #endif
 };
