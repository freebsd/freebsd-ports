--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc.orig	2018-06-13 00:10:24.000000000 +0200
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc	2018-07-20 15:29:23.131774000 +0200
@@ -178,6 +178,9 @@
 // static
 bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
                                  mojom::RawOSMemDump* dump) {
+#if defined(OS_BSD)
+  return false;
+#else
   base::ScopedFD autoclose = OpenStatm(pid);
   int statm_fd = autoclose.get();
 
@@ -203,6 +206,7 @@
   dump->resident_set_kb = process_metrics->GetResidentSetSize() / 1024;
 
   return true;
+#endif
 }
 
 // static
