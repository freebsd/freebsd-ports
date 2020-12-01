--- base/process/process_linux.cc.orig	2020-11-13 06:36:34 UTC
+++ base/process/process_linux.cc
@@ -24,7 +24,9 @@ namespace base {
 
 namespace {
 
+#if !defined(OS_BSD)
 const int kForegroundPriority = 0;
+#endif
 
 #if defined(OS_CHROMEOS) || BUILDFLAG(IS_LACROS)
 // We are more aggressive in our lowering of background process priority
@@ -69,7 +71,7 @@ struct CGroups {
     return groups;
   }
 };
-#else
+#elif !defined(OS_BSD)
 const int kBackgroundPriority = 5;
 #endif  // defined(OS_CHROMEOS) || BUILDFLAG(IS_LACROS)
 
@@ -96,13 +98,18 @@ Time Process::CreationTime() const {
   if (!start_ticks)
     return Time();
 
+#if defined(OS_BSD)
+  return Time::FromTimeT(start_ticks);
+#else
   TimeDelta start_offset = internal::ClockTicksToTimeDelta(start_ticks);
   Time boot_time = internal::GetBootTime();
   if (boot_time.is_null())
     return Time();
   return Time(boot_time + start_offset);
+#endif
 }
 
+#if !defined(OS_BSD)
 // static
 bool Process::CanBackgroundProcesses() {
 #if defined(OS_CHROMEOS) || BUILDFLAG(IS_LACROS)
@@ -154,6 +161,7 @@ bool Process::SetProcessBackgrounded(bool background) 
   DPCHECK(result == 0);
   return result == 0;
 }
+#endif // !defined(OS_BSD)
 
 #if defined(OS_CHROMEOS) || BUILDFLAG(IS_LACROS)
 bool IsProcessBackgroundedCGroup(const StringPiece& cgroup_contents) {
