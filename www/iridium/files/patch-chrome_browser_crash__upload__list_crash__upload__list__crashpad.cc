--- chrome/browser/crash_upload_list/crash_upload_list_crashpad.cc.orig	2019-12-31 13:56:21 UTC
+++ chrome/browser/crash_upload_list/crash_upload_list_crashpad.cc
@@ -42,6 +42,9 @@ CrashUploadListCrashpad::CrashUploadListCrashpad() = d
 CrashUploadListCrashpad::~CrashUploadListCrashpad() = default;
 
 std::vector<UploadList::UploadInfo> CrashUploadListCrashpad::LoadUploadList() {
+#if defined(OS_BSD)
+  return std::vector<UploadInfo>();
+#else
   std::vector<crash_reporter::Report> reports;
   crash_reporter::GetReports(&reports);
 
@@ -53,13 +56,18 @@ std::vector<UploadList::UploadInfo> CrashUploadListCra
                    ReportUploadStateToUploadInfoState(report.state)));
   }
   return uploads;
+#endif
 }
 
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
