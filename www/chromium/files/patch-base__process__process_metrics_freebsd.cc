--- ./base/process/process_metrics_freebsd.cc.orig	2013-09-03 09:09:03.000000000 +0200
+++ ./base/process/process_metrics_freebsd.cc	2013-09-07 21:30:29.000000000 +0200
@@ -4,6 +4,10 @@
 
 #include "base/process/process_metrics.h"
 
+#include "base/sys_info.h"
+
+#include <unistd.h> /* getpagesize() */
+
 namespace base {
 
 ProcessMetrics::ProcessMetrics(ProcessHandle process)
