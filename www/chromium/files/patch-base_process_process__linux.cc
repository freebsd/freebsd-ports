--- base/process/process_linux.cc.orig	2019-02-01 23:15:53.491332000 +0100
+++ base/process/process_linux.cc	2019-02-01 23:16:56.937810000 +0100
@@ -88,6 +88,7 @@
   return Time(boot_time + start_offset);
 }
 
+#if !defined(OS_BSD)
 // static
 bool Process::CanBackgroundProcesses() {
 #if defined(OS_CHROMEOS)
@@ -139,6 +140,7 @@
   DPCHECK(result == 0);
   return result == 0;
 }
+#endif // !defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
 bool IsProcessBackgroundedCGroup(const StringPiece& cgroup_contents) {
