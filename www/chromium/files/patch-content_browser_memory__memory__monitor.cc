--- content/browser/memory/memory_monitor.cc.orig	2016-12-01 23:02:12.000000000 +0000
+++ content/browser/memory/memory_monitor.cc	2016-12-14 18:20:00.515155000 +0000
@@ -8,6 +8,7 @@
 
 namespace content {
 
+#if !defined(OS_FREEBSD)
 // static
 MemoryMonitorDelegate* MemoryMonitorDelegate::GetInstance() {
   return base::Singleton<
@@ -21,5 +22,6 @@
     base::SystemMemoryInfoKB* mem_info) {
   base::GetSystemMemoryInfo(mem_info);
 }
+#endif // !defined(OS_FREEBSD)
 
 }  // namespace content
