--- chrome/browser/memory_details_linux.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/memory_details_linux.cc
@@ -71,9 +71,10 @@ ProcessData GetProcessDataMemoryInformation(
     std::unique_ptr<base::ProcessMetrics> metrics(
         base::ProcessMetrics::CreateProcessMetrics(pid));
     metrics->GetWorkingSetKBytes(&pmi.working_set);
+#if !defined(OS_BSD)
     pmi.num_open_fds = metrics->GetOpenFdCount();
     pmi.open_fds_soft_limit = metrics->GetOpenFdSoftLimit();
-
+#endif
     process_data.processes.push_back(pmi);
   }
   return process_data;
