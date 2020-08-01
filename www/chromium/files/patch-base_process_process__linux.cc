--- base/process/process_linux.cc.orig	2020-07-07 21:57:30 UTC
+++ base/process/process_linux.cc
@@ -80,6 +80,9 @@ Time Process::CreationTime() const {
                                   internal::VM_STARTTIME)
                             : internal::ReadProcStatsAndGetFieldAsInt64(
                                   Pid(), internal::VM_STARTTIME);
+#if defined(OS_BSD)
+  return Time::FromTimeT(start_ticks);
+#else
   if (!start_ticks)
     return Time();
   TimeDelta start_offset = internal::ClockTicksToTimeDelta(start_ticks);
@@ -87,8 +90,10 @@ Time Process::CreationTime() const {
   if (boot_time.is_null())
     return Time();
   return Time(boot_time + start_offset);
+#endif
 }
 
+#if !defined(OS_BSD)
 // static
 bool Process::CanBackgroundProcesses() {
 #if defined(OS_CHROMEOS)
@@ -140,6 +145,7 @@ bool Process::SetProcessBackgrounded(bool background) 
   DPCHECK(result == 0);
   return result == 0;
 }
+#endif // !defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
 bool IsProcessBackgroundedCGroup(const StringPiece& cgroup_contents) {
