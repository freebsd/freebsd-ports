--- cef/libcef/browser/file_dialog_manager.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/file_dialog_manager.cc
@@ -398,7 +398,7 @@ void CefFileDialogManager::RunSelectFile
     return;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // We can't use GtkUi in combination with multi-threaded-message-loop because
   // Chromium's GTK implementation doesn't use GDK threads.
   if (!!CefContext::Get()->settings().multi_threaded_message_loop) {
