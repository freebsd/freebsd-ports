--- content/browser/time_zone_monitor_linux.cc.orig	2016-05-11 19:02:21 UTC
+++ content/browser/time_zone_monitor_linux.cc
@@ -53,6 +53,9 @@ class TimeZoneMonitorLinuxImpl
       : base::RefCountedThreadSafe<TimeZoneMonitorLinuxImpl>(),
         file_path_watchers_(),
         owner_(owner) {
+  }
+
+  void StartWatching() {
     DCHECK_CURRENTLY_ON(BrowserThread::UI);
     BrowserThread::PostTask(
         BrowserThread::FILE,
@@ -149,6 +152,9 @@ TimeZoneMonitorLinux::TimeZoneMonitorLin
   // changed.
   if (!getenv("TZ")) {
     impl_ = new TimeZoneMonitorLinuxImpl(this);
+    if (impl_.get()) {
+      impl_->StartWatching();
+    }
   }
 }
 
