--- src/3rdparty/chromium/net/disk_cache/simple/simple_file_tracker.cc.orig	2022-06-17 14:20:10 UTC
+++ src/3rdparty/chromium/net/disk_cache/simple/simple_file_tracker.cc
@@ -29,7 +29,17 @@ void RecordFileDescripterLimiterOp(FileDescriptorLimit
 }  // namespace
 
 SimpleFileTracker::SimpleFileTracker(int file_limit)
+#if defined(OS_OPENBSD)
+{
+  // cap the file descriptor limit at 85% of the size of the
+  // file descriptor table and also substract the amount of
+  // currently used file descriptors as this should give us
+  // enough reserve to avoid hitting the limit 
+  file_limit_ = (getdtablesize() * 0.85) -  getdtablecount();
+}
+#else
     : file_limit_(file_limit) {}
+#endif
 
 SimpleFileTracker::~SimpleFileTracker() {
   DCHECK(lru_.empty());
