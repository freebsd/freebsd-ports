--- components/storage_monitor/storage_monitor.cc.orig	2017-04-19 19:06:33 UTC
+++ components/storage_monitor/storage_monitor.cc
@@ -85,6 +85,7 @@ std::vector<StorageInfo> StorageMonitor:
 
 void StorageMonitor::EnsureInitialized(base::Closure callback) {
   DCHECK(thread_checker_.CalledOnValidThread());
+//#if !defined(OS_BSD) //XXX(rene) why disabled?
   if (initialized_) {
     if (!callback.is_null())
       callback.Run();
@@ -100,6 +101,7 @@ void StorageMonitor::EnsureInitialized(b
 
   initializing_ = true;
   Init();
+//#endif
 }
 
 bool StorageMonitor::IsInitialized() const {
