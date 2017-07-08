--- base/trace_event/trace_log.cc.orig	2017-06-05 19:03:01 UTC
+++ base/trace_event/trace_log.cc
@@ -1504,7 +1504,7 @@ void TraceLog::AddMetadataEventsWhileLocked() {
                             process_name_);
   }
 
-#if !defined(OS_NACL) && !defined(OS_IOS)
+#if !defined(OS_NACL) && !defined(OS_IOS) && !defined(OS_BSD)
   Time process_creation_time = CurrentProcessInfo::CreationTime();
   if (!process_creation_time.is_null()) {
     TimeDelta process_uptime = Time::Now() - process_creation_time;
@@ -1512,7 +1512,7 @@ void TraceLog::AddMetadataEventsWhileLocked() {
                             current_thread_id, "process_uptime_seconds",
                             "uptime", process_uptime.InSeconds());
   }
-#endif  // !defined(OS_NACL) && !defined(OS_IOS)
+#endif  // !defined(OS_NACL) && !defined(OS_IOS) && !defined(OS_BSD)
 
   if (!process_labels_.empty()) {
     std::vector<base::StringPiece> labels;
