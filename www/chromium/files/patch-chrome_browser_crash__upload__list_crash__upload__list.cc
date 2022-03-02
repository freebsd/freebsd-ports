--- chrome/browser/crash_upload_list/crash_upload_list.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/crash_upload_list/crash_upload_list.cc
@@ -52,7 +52,7 @@ scoped_refptr<UploadList> CreateCrashUploadList() {
 // to log uploads in CrashUploadList::kReporterLogFilename.
 // Linux is handled below.
 #if !(BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-      BUILDFLAG(IS_LINUX))
+      BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   if (crash_reporter::IsCrashpadEnabled()) {
     return new CrashUploadListCrashpad();
   }
