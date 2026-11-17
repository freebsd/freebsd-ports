--- chrome/browser/download/download_file_picker.cc.orig	2026-11-17 11:49:09 UTC
+++ chrome/browser/download/download_file_picker.cc
@@ -20,7 +20,7 @@
 #include "ui/display/types/display_constants.h"
 #include "ui/shell_dialogs/selected_file_info.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_window.h"
 #include "chrome/browser/ui/browser_window/public/browser_window_interface_iterator.h"
 #include "ui/aura/window.h"
@@ -98,7 +98,7 @@ DownloadFilePicker::DownloadFilePicker(download::Downl
   // dialog in Linux (See SelectFileImpl() in select_file_dialog_linux_gtk.cc).
   // and windows.Here we make owning_window host to browser current active
   // window if it is null. https://crbug.com/40825014
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (!owning_window || !owning_window->GetHost()) {
     if (BrowserWindowInterface* browser =
             GetLastActiveBrowserWindowInterfaceWithAnyProfile();
