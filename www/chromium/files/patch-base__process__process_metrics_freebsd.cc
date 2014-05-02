--- ./base/process/process_metrics_freebsd.cc.orig	2014-04-24 22:36:10.000000000 +0200
+++ ./base/process/process_metrics_freebsd.cc	2014-04-24 23:23:41.000000000 +0200
@@ -4,6 +4,10 @@
 
 #include "base/process/process_metrics.h"
 
+#include "base/sys_info.h"
+
+#include <unistd.h> /* getpagesize() */
+
 namespace base {
 
 ProcessMetrics::ProcessMetrics(ProcessHandle process)
