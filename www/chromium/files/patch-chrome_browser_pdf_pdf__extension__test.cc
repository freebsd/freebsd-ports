--- chrome/browser/pdf/pdf_extension_test.cc.orig	2020-09-08 19:14:00 UTC
+++ chrome/browser/pdf/pdf_extension_test.cc
@@ -1926,7 +1926,7 @@ class PDFExtensionClipboardTest : public PDFExtensionT
 
   // Checks the Linux selection clipboard by polling.
   void CheckSelectionClipboard(const std::string& expected) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     CheckClipboard(ui::ClipboardBuffer::kSelection, expected);
 #endif
   }
