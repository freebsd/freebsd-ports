--- services/device/time_zone_monitor/time_zone_monitor_linux.cc.orig	2017-04-19 19:06:37 UTC
+++ services/device/time_zone_monitor/time_zone_monitor_linux.cc
@@ -59,6 +59,9 @@ class TimeZoneMonitorLinuxImpl
         main_task_runner_(base::ThreadTaskRunnerHandle::Get()),
         file_task_runner_(file_task_runner),
         owner_(owner) {
+  }
+
+  void StartWatching() {
     DCHECK(main_task_runner_->RunsTasksOnCurrentThread());
     file_task_runner_->PostTask(
         FROM_HERE,
@@ -150,6 +153,9 @@ TimeZoneMonitorLinux::TimeZoneMonitorLin
   // changed.
   if (!getenv("TZ")) {
     impl_ = new TimeZoneMonitorLinuxImpl(this, file_task_runner);
+    if (impl_.get()) {
+      impl_->StartWatching();
+    }
   }
 }
 
