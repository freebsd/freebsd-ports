--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc.orig	2018-05-09 21:05:55.000000000 +0200
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc	2018-08-16 12:01:06.316665000 +0200
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
