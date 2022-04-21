--- chrome/browser/download/download_file_picker.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/download/download_file_picker.cc
@@ -14,7 +14,7 @@
 #include "content/public/browser/download_manager.h"
 #include "content/public/browser/web_contents.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/browser_window.h"
 #include "ui/aura/window.h"
@@ -74,7 +74,7 @@ DownloadFilePicker::DownloadFilePicker(DownloadItem* i
   // dialog in Linux. See SelectFileImpl() in select_file_dialog_linux_gtk.cc.
   // Here we make owning_window host to browser current active window
   // if it is null. https://crbug.com/1301898
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!owning_window || !owning_window->GetHost())
     owning_window =
         chrome::FindBrowserWithActiveWindow()->window()->GetNativeWindow();
