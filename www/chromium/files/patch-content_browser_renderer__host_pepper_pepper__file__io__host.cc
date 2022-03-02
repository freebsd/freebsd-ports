--- content/browser/renderer_host/pepper/pepper_file_io_host.cc.orig	2022-02-28 16:54:41 UTC
+++ content/browser/renderer_host/pepper/pepper_file_io_host.cc
@@ -456,7 +456,7 @@ void PepperFileIOHost::OnLocalFileOpened(
     ppapi::host::ReplyMessageContext reply_context,
     const base::FilePath& path,
     base::File::Error error_code) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Quarantining a file before its contents are available is only supported on
   // Windows and Linux.
   if (!FileOpenForWrite(open_flags_) || error_code != base::File::FILE_OK) {
@@ -490,7 +490,7 @@ void PepperFileIOHost::OnLocalFileOpened(
 #endif
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void PepperFileIOHost::OnLocalFileQuarantined(
     ppapi::host::ReplyMessageContext reply_context,
     const base::FilePath& path,
