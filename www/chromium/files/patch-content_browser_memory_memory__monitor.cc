--- content/browser/memory/memory_monitor.cc.orig	2017-06-05 19:03:07 UTC
+++ content/browser/memory/memory_monitor.cc
@@ -8,6 +8,7 @@
 
 namespace content {
 
+#if !defined(OS_FREEBSD)
 // static
 MemoryMonitorDelegate* MemoryMonitorDelegate::GetInstance() {
   return base::Singleton<
@@ -21,8 +22,9 @@ void MemoryMonitorDelegate::GetSystemMemoryInfo(
     base::SystemMemoryInfoKB* mem_info) {
   base::GetSystemMemoryInfo(mem_info);
 }
+#endif // !defined(OS_FREEBSD)
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) && !defined(OS_FREEBSD)
 // TODO(bashi,bcwhite): Remove when memory monitor for mac is available.
 std::unique_ptr<MemoryMonitor> CreateMemoryMonitor() {
   NOTREACHED();
