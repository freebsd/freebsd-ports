--- chrome/browser/pdf/pdf_extension_test.cc.orig	2021-09-24 04:25:58 UTC
+++ chrome/browser/pdf/pdf_extension_test.cc
@@ -812,11 +812,11 @@ IN_PROC_BROWSER_TEST_P(PDFPluginDisabledTest, DirectNa
 }
 
 // TODO(crbug.com/1201401): fix flakiness and reenable
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
 #define MAYBE_EmbedPdfPlaceholderWithCSP DISABLED_EmbedPdfPlaceholderWithCSP
 #else
 #define MAYBE_EmbedPdfPlaceholderWithCSP EmbedPdfPlaceholderWithCSP
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
 IN_PROC_BROWSER_TEST_P(PDFPluginDisabledTest,
                        MAYBE_EmbedPdfPlaceholderWithCSP) {
   // Navigate to a page with CSP that uses <embed> to embed a PDF as a plugin.
@@ -2404,7 +2404,7 @@ IN_PROC_BROWSER_TEST_F(PDFExtensionClipboardTest,
 }
 
 // Flaky on Linux (https://crbug.com/1121446)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #define MAYBE_CombinedShiftArrowPresses DISABLED_CombinedShiftArrowPresses
 #else
 #define MAYBE_CombinedShiftArrowPresses CombinedShiftArrowPresses
