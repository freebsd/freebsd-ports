--- base/process/process_metrics.cc.orig	2017-12-23 21:01:02.481980000 +0100
+++ base/process/process_metrics.cc	2017-12-23 21:01:15.848759000 +0100
@@ -10,7 +10,7 @@
 #include "base/values.h"
 #include "build/build_config.h"
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 namespace {
 int CalculateEventsPerSecond(uint64_t event_count,
                              uint64_t* last_event_count,
