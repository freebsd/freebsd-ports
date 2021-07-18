--- chrome/browser/feedback/system_logs/log_sources/crash_ids_source.cc.orig	2021-04-23 20:22:19 UTC
+++ chrome/browser/feedback/system_logs/log_sources/crash_ids_source.cc
@@ -42,7 +42,9 @@ constexpr base::TimeDelta k120DaysTimeDelta = base::Ti
 
 CrashIdsSource::CrashIdsSource()
     : SystemLogsSource("CrashId"),
+#if !defined(OS_BSD)
       crash_upload_list_(CreateCrashUploadList()),
+#endif
       pending_crash_list_loading_(false) {}
 
 CrashIdsSource::~CrashIdsSource() {}
