--- content/browser/memory/memory_monitor_linux.cc.orig	2016-12-01 23:02:12.000000000 +0000
+++ content/browser/memory/memory_monitor_linux.cc	2016-12-14 18:23:30.803202000 +0000
@@ -11,6 +11,7 @@
 
 namespace {
 
+#if !defined(OS_FREEBSD)
 // The number of bits to shift to convert KiB to MiB.
 const int kShiftKiBtoMiB = 10;
 
@@ -48,5 +49,8 @@
 std::unique_ptr<MemoryMonitor> CreateMemoryMonitor() {
   return MemoryMonitorLinux::Create(MemoryMonitorDelegate::GetInstance());
 }
+#endif // !defined(OS_FREEBSD)
+
+}
 
 }  // namespace content
