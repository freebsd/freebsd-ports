--- src/3rdparty/chromium/components/crash/core/browser/crash_upload_list_crashpad.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/components/crash/core/browser/crash_upload_list_crashpad.cc
@@ -51,9 +51,13 @@ void CrashUploadListCrashpad::ClearUploadList(const ba
 
 void CrashUploadListCrashpad::ClearUploadList(const base::Time& begin,
                                               const base::Time& end) {
+#if !defined(OS_BSD)
   crash_reporter::ClearReportsBetween(begin, end);
+#endif
 }
 
 void CrashUploadListCrashpad::RequestSingleUpload(const std::string& local_id) {
+#if !defined(OS_BSD)
   crash_reporter::RequestSingleCrashUpload(local_id);
+#endif
 }
