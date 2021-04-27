--- chrome/browser/crash_upload_list/crash_upload_list.cc.orig	2021-04-14 18:40:53 UTC
+++ chrome/browser/crash_upload_list/crash_upload_list.cc
@@ -39,7 +39,7 @@ scoped_refptr<UploadList> CreateCrashUploadList() {
 // ChromeOS uses crash_sender as its uploader even when Crashpad is enabled,
 // which isn't compatible with CrashUploadListCrashpad. crash_sender continues
 // to log uploads in CrashUploadList::kReporterLogFilename.
-#if !(BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if !(BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   if (crash_reporter::IsCrashpadEnabled()) {
     return new CrashUploadListCrashpad();
   }
