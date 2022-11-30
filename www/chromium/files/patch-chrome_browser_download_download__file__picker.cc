--- chrome/browser/download/download_file_picker.cc.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/download/download_file_picker.cc
@@ -16,7 +16,7 @@
 #include "content/public/browser/download_manager.h"
 #include "content/public/browser/web_contents.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_list.h"
 #include "chrome/browser/ui/browser_window.h"
 #include "ui/aura/window.h"
@@ -85,7 +85,7 @@ DownloadFilePicker::DownloadFilePicker(download::Downl
   // dialog in Linux (See SelectFileImpl() in select_file_dialog_linux_gtk.cc).
   // and windows.Here we make owning_window host to browser current active
   // window if it is null. https://crbug.com/1301898
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (!owning_window || !owning_window->GetHost()) {
     owning_window = BrowserList::GetInstance()
                         ->GetLastActive()
