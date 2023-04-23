--- src/3rdparty/chromium/components/crash/core/browser/crash_upload_list_crashpad.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/components/crash/core/browser/crash_upload_list_crashpad.cc
@@ -37,7 +37,9 @@ std::vector<UploadList::UploadInfo> CrashUploadListCra
 
 std::vector<UploadList::UploadInfo> CrashUploadListCrashpad::LoadUploadList() {
   std::vector<crash_reporter::Report> reports;
+#if !defined(OS_BSD)
   crash_reporter::GetReports(&reports);
+#endif
 
   std::vector<UploadInfo> uploads;
   for (const crash_reporter::Report& report : reports) {
@@ -51,9 +53,13 @@ void CrashUploadListCrashpad::ClearUploadList(const ba
 
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
