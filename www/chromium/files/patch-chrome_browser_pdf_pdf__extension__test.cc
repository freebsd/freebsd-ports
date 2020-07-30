--- chrome/browser/pdf/pdf_extension_test.cc.orig	2020-07-13 09:21:17 UTC
+++ chrome/browser/pdf/pdf_extension_test.cc
@@ -1796,7 +1796,7 @@ class PDFExtensionClipboardTest : public PDFExtensionT
 
   // Checks the Linux selection clipboard by polling.
   void CheckSelectionClipboard(const std::string& expected) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     CheckClipboard(ui::ClipboardBuffer::kSelection, expected);
 #endif
   }
