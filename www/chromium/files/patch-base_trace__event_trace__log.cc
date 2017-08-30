--- base/trace_event/trace_log.cc.orig	2017-07-25 21:04:48.000000000 +0200
+++ base/trace_event/trace_log.cc	2017-08-01 22:41:16.236310000 +0200
@@ -1501,7 +1501,7 @@
   }
 
 // See https://crbug.com/726484 for Fuchsia.
-#if !defined(OS_NACL) && !defined(OS_IOS) && !defined(OS_FUCHSIA)
+#if !defined(OS_NACL) && !defined(OS_IOS) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
   Time process_creation_time = CurrentProcessInfo::CreationTime();
   if (!process_creation_time.is_null()) {
     TimeDelta process_uptime = Time::Now() - process_creation_time;
@@ -1509,7 +1509,7 @@
                             current_thread_id, "process_uptime_seconds",
                             "uptime", process_uptime.InSeconds());
   }
-#endif  // !defined(OS_NACL) && !defined(OS_IOS) && !defined(OS_FUCHSIA)
+#endif  // !defined(OS_NACL) && !defined(OS_IOS) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 
   if (!process_labels_.empty()) {
     std::vector<base::StringPiece> labels;
