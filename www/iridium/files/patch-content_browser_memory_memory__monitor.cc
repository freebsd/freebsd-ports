--- content/browser/memory/memory_monitor.cc.orig	2018-01-04 21:05:50.000000000 +0100
+++ content/browser/memory/memory_monitor.cc	2018-01-27 19:06:05.251190000 +0100
@@ -22,7 +22,7 @@
   base::GetSystemMemoryInfo(mem_info);
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // TODO(bashi,bcwhite): Remove when memory monitor for mac is available.
 std::unique_ptr<MemoryMonitor> CreateMemoryMonitor() {
   NOTREACHED();
