--- chrome/browser/crash_upload_list/crash_upload_list.cc.orig	2022-06-17 14:20:10 UTC
+++ chrome/browser/crash_upload_list/crash_upload_list.cc
@@ -50,7 +50,7 @@ scoped_refptr<UploadList> CreateCrashUploadList() {
 // which isn't compatible with CrashUploadListCrashpad. crash_sender continues
 // to log uploads in CrashUploadList::kReporterLogFilename.
 // Linux is handled below.
-#if !(BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX))
+#if !(BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   if (crash_reporter::IsCrashpadEnabled()) {
     return new CrashUploadListCrashpad();
   }
