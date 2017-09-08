--- content/browser/memory/swap_metrics_observer_linux.cc.orig	2017-08-10 15:31:54.593212000 +0200
+++ content/browser/memory/swap_metrics_observer_linux.cc	2017-08-10 15:37:58.561111000 +0200
@@ -12,10 +12,12 @@
 namespace {
 
 bool HasSwap() {
+#if !defined(OS_BSD)
   base::SystemMemoryInfoKB memory_info;
   if (!base::GetSystemMemoryInfo(&memory_info))
     return false;
   return memory_info.swap_total > 0;
+#endif
 }
 
 }  // namespace
