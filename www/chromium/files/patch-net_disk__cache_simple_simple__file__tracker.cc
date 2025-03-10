--- net/disk_cache/simple/simple_file_tracker.cc.orig	2025-03-05 08:14:56 UTC
+++ net/disk_cache/simple/simple_file_tracker.cc
@@ -37,7 +37,17 @@ bool SimpleFileTracker::TrackedFiles::InLRUList() cons
 }
 
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
