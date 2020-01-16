--- chrome/browser/download/download_commands.cc.orig	2019-12-16 21:50:42 UTC
+++ chrome/browser/download/download_commands.cc
@@ -26,7 +26,7 @@
 #include "net/base/url_util.h"
 #include "ui/base/clipboard/scoped_clipboard_writer.h"
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/scoped_tabbed_browser_displayer.h"
@@ -153,7 +153,7 @@ void DownloadCommands::ExecuteCommand(Command command)
   model_->ExecuteCommand(this, command);
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 Browser* DownloadCommands::GetBrowser() const {
   chrome::ScopedTabbedBrowserDisplayer browser_displayer(model_->profile());
@@ -176,12 +176,12 @@ bool DownloadCommands::CanOpenPdfInSystemViewer() cons
   return IsDownloadPdf() &&
          (IsAdobeReaderDefaultPDFViewer() ? is_adobe_pdf_reader_up_to_date
                                           : true);
-#elif defined(OS_MACOSX) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return IsDownloadPdf();
 #endif
 }
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 void DownloadCommands::CopyFileAsImageToClipboard() {
   if (model_->GetState() != download::DownloadItem::COMPLETE ||
