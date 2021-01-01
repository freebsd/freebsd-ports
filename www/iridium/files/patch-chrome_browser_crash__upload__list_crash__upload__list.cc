--- chrome/browser/crash_upload_list/crash_upload_list.cc.orig	2019-12-31 13:55:02 UTC
+++ chrome/browser/crash_upload_list/crash_upload_list.cc
@@ -38,7 +38,7 @@ scoped_refptr<UploadList> CreateCrashUploadList() {
 // ChromeOS uses crash_sender as its uploader even when Crashpad is enabled,
 // which isn't compatible with CrashUploadListCrashpad. crash_sender continues
 // to log uploads in CrashUploadList::kReporterLogFilename.
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   if (crash_reporter::IsCrashpadEnabled()) {
     return new CrashUploadListCrashpad();
   }
