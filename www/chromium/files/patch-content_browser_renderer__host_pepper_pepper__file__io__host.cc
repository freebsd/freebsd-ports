--- content/browser/renderer_host/pepper/pepper_file_io_host.cc.orig	2019-10-21 19:06:32 UTC
+++ content/browser/renderer_host/pepper/pepper_file_io_host.cc
@@ -433,7 +433,7 @@ void PepperFileIOHost::OnLocalFileOpened(
     ppapi::host::ReplyMessageContext reply_context,
     const base::FilePath& path,
     base::File::Error error_code) {
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   // Quarantining a file before its contents are available is only supported on
   // Windows and Linux.
   if (!FileOpenForWrite(open_flags_) || error_code != base::File::FILE_OK) {
@@ -453,7 +453,7 @@ void PepperFileIOHost::OnLocalFileOpened(
 #endif
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 void PepperFileIOHost::OnLocalFileQuarantined(
     ppapi::host::ReplyMessageContext reply_context,
     const base::FilePath& path,
