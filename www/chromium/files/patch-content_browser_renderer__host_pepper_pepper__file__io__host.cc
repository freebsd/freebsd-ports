--- content/browser/renderer_host/pepper/pepper_file_io_host.cc.orig	2021-12-14 11:45:05 UTC
+++ content/browser/renderer_host/pepper/pepper_file_io_host.cc
@@ -456,7 +456,7 @@ void PepperFileIOHost::OnLocalFileOpened(
     ppapi::host::ReplyMessageContext reply_context,
     const base::FilePath& path,
     base::File::Error error_code) {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Quarantining a file before its contents are available is only supported on
   // Windows and Linux.
   if (!FileOpenForWrite(open_flags_) || error_code != base::File::FILE_OK) {
@@ -490,7 +490,7 @@ void PepperFileIOHost::OnLocalFileOpened(
 #endif
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void PepperFileIOHost::OnLocalFileQuarantined(
     ppapi::host::ReplyMessageContext reply_context,
     const base::FilePath& path,
