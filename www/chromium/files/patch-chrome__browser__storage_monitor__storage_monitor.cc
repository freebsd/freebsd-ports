--- chrome/browser/storage_monitor/storage_monitor.cc.orig	2013-08-23 15:58:31.000000000 +0300
+++ chrome/browser/storage_monitor/storage_monitor.cc	2013-08-23 15:59:02.000000000 +0300
@@ -63,6 +63,7 @@
 
 void StorageMonitor::EnsureInitialized(base::Closure callback) {
   DCHECK(thread_checker_.CalledOnValidThread());
+#if !defined(OS_BSD)
   if (initialized_) {
     if (!callback.is_null())
       callback.Run();
@@ -78,6 +79,7 @@
 
   initializing_ = true;
   Init();
+#endif
 }
 
 bool StorageMonitor::IsInitialized() {
