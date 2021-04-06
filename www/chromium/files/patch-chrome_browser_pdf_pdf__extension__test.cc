--- chrome/browser/pdf/pdf_extension_test.cc.orig	2021-03-12 23:57:18 UTC
+++ chrome/browser/pdf/pdf_extension_test.cc
@@ -2188,7 +2188,7 @@ class PDFExtensionClipboardTest : public PDFExtensionT
                                           const std::string& expected) {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
     DoActionAndCheckClipboard(std::move(action),
                               ui::ClipboardBuffer::kSelection, expected);
 #else
@@ -2320,7 +2320,7 @@ IN_PROC_BROWSER_TEST_P(PDFExtensionClipboardTest,
 // Flaky on ChromeOS (https://crbug.com/1121446)
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #define MAYBE_CombinedShiftArrowPresses DISABLED_CombinedShiftArrowPresses
 #else
 #define MAYBE_CombinedShiftArrowPresses CombinedShiftArrowPresses
