--- components/metrics/system_memory_stats_recorder_linux.cc.orig	2015-09-03 20:30:21.188785000 -0400
+++ components/metrics/system_memory_stats_recorder_linux.cc	2015-09-03 20:25:00.522580000 -0400
@@ -29,6 +29,7 @@
   UMA_HISTOGRAM_LINEAR(name, sample, 2500, 50)
 
 void RecordMemoryStats(RecordMemoryStatsType type) {
+#if !defined(OS_FREEBSD)
   base::SystemMemoryInfoKB memory;
   if (!base::GetSystemMemoryInfo(&memory))
     return;
@@ -92,6 +93,7 @@
       break;
     }
   }
+#endif // !defined(OS_FREEBSD)
 }
 
 }  // namespace memory
