--- ./base/process/process_metrics_freebsd.cc.orig	2014-04-30 22:41:43.000000000 +0200
+++ ./base/process/process_metrics_freebsd.cc	2014-05-04 14:38:46.000000000 +0200
@@ -10,6 +10,8 @@
 
 #include "base/sys_info.h"
 
+#include <unistd.h> /* getpagesize() */
+
 namespace base {
 
 ProcessMetrics::ProcessMetrics(ProcessHandle process)
