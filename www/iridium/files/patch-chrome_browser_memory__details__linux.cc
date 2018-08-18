--- chrome/browser/memory_details_linux.cc.orig	2018-06-13 00:10:06.000000000 +0200
+++ chrome/browser/memory_details_linux.cc	2018-07-20 00:12:53.799188000 +0200
@@ -70,8 +70,10 @@
 
     std::unique_ptr<base::ProcessMetrics> metrics(
         base::ProcessMetrics::CreateProcessMetrics(pid));
+#if !defined(OS_BSD)
     pmi.num_open_fds = metrics->GetOpenFdCount();
     pmi.open_fds_soft_limit = metrics->GetOpenFdSoftLimit();
+#endif
 
     process_data.processes.push_back(pmi);
   }
