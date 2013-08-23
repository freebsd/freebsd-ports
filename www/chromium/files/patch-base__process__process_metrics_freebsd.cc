--- base/process/process_metrics_freebsd.cc.orig	2013-08-17 19:21:48.000000000 +0300
+++ base/process/process_metrics_freebsd.cc	2013-08-17 19:22:18.000000000 +0300
@@ -4,6 +4,8 @@
 
 #include "base/process/process_metrics.h"
 
+#include "base/sys_info.h"
+
 namespace base {
 
 ProcessMetrics::ProcessMetrics(ProcessHandle process)
