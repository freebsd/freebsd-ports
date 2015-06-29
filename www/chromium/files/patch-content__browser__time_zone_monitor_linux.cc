--- content/browser/time_zone_monitor_linux.cc.orig	2015-05-25 19:00:26 UTC
+++ content/browser/time_zone_monitor_linux.cc
@@ -51,6 +51,9 @@
       : base::RefCountedThreadSafe<TimeZoneMonitorLinuxImpl>(),
         file_path_watchers_(),
         owner_(owner) {
+  }
+
+  void StartWatching() {
     DCHECK_CURRENTLY_ON(BrowserThread::UI);
     BrowserThread::PostTask(
         BrowserThread::FILE,
@@ -147,6 +150,9 @@
   // changed.
   if (!getenv("TZ")) {
     impl_ = new TimeZoneMonitorLinuxImpl(this);
+    if (impl_.get()) {
+      impl_->StartWatching();
+    }
   }
 }
 
