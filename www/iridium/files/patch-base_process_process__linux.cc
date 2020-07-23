--- base/process/process_linux.cc.orig	2020-03-16 18:39:41 UTC
+++ base/process/process_linux.cc
@@ -79,6 +79,9 @@ Time Process::CreationTime() const {
                                   internal::VM_STARTTIME)
                             : internal::ReadProcStatsAndGetFieldAsInt64(
                                   Pid(), internal::VM_STARTTIME);
+#if defined(OS_BSD)
+  return Time::FromTimeT(start_ticks);
+#else
   if (!start_ticks)
     return Time();
   TimeDelta start_offset = internal::ClockTicksToTimeDelta(start_ticks);
@@ -86,8 +89,10 @@ Time Process::CreationTime() const {
   if (boot_time.is_null())
     return Time();
   return Time(boot_time + start_offset);
+#endif
 }
 
+#if !defined(OS_BSD)
 // static
 bool Process::CanBackgroundProcesses() {
 #if defined(OS_CHROMEOS)
@@ -139,6 +144,7 @@ bool Process::SetProcessBackgrounded(bool background) 
   DPCHECK(result == 0);
   return result == 0;
 }
+#endif // !defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
 bool IsProcessBackgroundedCGroup(const StringPiece& cgroup_contents) {
