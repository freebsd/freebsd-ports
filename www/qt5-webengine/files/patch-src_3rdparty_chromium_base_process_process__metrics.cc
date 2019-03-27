--- src/3rdparty/chromium/base/process/process_metrics.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/process/process_metrics.cc
@@ -10,7 +10,7 @@
 #include "base/values.h"
 #include "build/build_config.h"
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 namespace {
 int CalculateEventsPerSecond(uint64_t event_count,
                              uint64_t* last_event_count,
