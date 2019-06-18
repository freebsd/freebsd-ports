--- base/process/process_linux.cc.orig	2019-03-11 22:00:51 UTC
+++ base/process/process_linux.cc
@@ -88,6 +88,7 @@ Time Process::CreationTime() const {
   return Time(boot_time + start_offset);
 }
 
+#if !defined(OS_BSD)
 // static
 bool Process::CanBackgroundProcesses() {
 #if defined(OS_CHROMEOS)
@@ -139,6 +140,7 @@ bool Process::SetProcessBackgrounded(bool background) 
   DPCHECK(result == 0);
   return result == 0;
 }
+#endif // !defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
 bool IsProcessBackgroundedCGroup(const StringPiece& cgroup_contents) {
