--- device/time_zone_monitor/time_zone_monitor_linux.cc.orig	2016-12-12 21:26:07 UTC
+++ device/time_zone_monitor/time_zone_monitor_linux.cc
@@ -58,6 +58,9 @@ class TimeZoneMonitorLinuxImpl
         main_task_runner_(base::ThreadTaskRunnerHandle::Get()),
         file_task_runner_(file_task_runner),
         owner_(owner) {
+ }
+
+ void StartWatching() {
     DCHECK(main_task_runner_->RunsTasksOnCurrentThread());
     file_task_runner_->PostTask(
         FROM_HERE,
@@ -152,6 +155,9 @@ TimeZoneMonitorLinux::TimeZoneMonitorLin
   // changed.
   if (!getenv("TZ")) {
     impl_ = new TimeZoneMonitorLinuxImpl(this, file_task_runner);
+    if (impl_.get()) {
+      impl_->StartWatching();
+    }
   }
 }
 
