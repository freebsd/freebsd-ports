--- chrome/browser/download/download_commands.cc.orig	2021-09-24 04:25:58 UTC
+++ chrome/browser/download/download_commands.cc
@@ -27,7 +27,7 @@
 #include "net/base/url_util.h"
 #include "ui/base/clipboard/scoped_clipboard_writer.h"
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC) || defined(OS_FUCHSIA)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_finder.h"
@@ -165,7 +165,7 @@ void DownloadCommands::ExecuteCommand(Command command)
   model_->ExecuteCommand(this, command);
 }
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
 Browser* DownloadCommands::GetBrowser() const {
@@ -200,7 +200,7 @@ bool DownloadCommands::CanOpenPdfInSystemViewer() cons
 #endif
 }
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
 void DownloadCommands::CopyFileAsImageToClipboard() {
