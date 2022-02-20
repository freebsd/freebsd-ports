--- chrome/browser/download/download_commands.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/download/download_commands.cc
@@ -27,7 +27,7 @@
 #include "ui/base/clipboard/scoped_clipboard_writer.h"
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC) || defined(OS_FUCHSIA)
+    defined(OS_MAC) || defined(OS_FUCHSIA) || defined(OS_BSD)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/scoped_tabbed_browser_displayer.h"
@@ -168,7 +168,7 @@ void DownloadCommands::ExecuteCommand(Command command)
 }
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 
 Browser* DownloadCommands::GetBrowser() const {
   if (!model_)
