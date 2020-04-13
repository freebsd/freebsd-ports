--- third_party/blink/renderer/controller/blink_initializer.cc.orig	2020-03-17 10:17:22 UTC
+++ third_party/blink/renderer/controller/blink_initializer.cc
@@ -69,7 +69,7 @@
 #include "third_party/blink/renderer/controller/memory_usage_monitor_posix.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_MACOSX) || \
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_MACOSX) || defined(OS_BSD) || \
     defined(OS_WIN)
 #include "third_party/blink/renderer/controller/highest_pmf_reporter.h"
 #include "third_party/blink/renderer/controller/user_level_memory_pressure_signal_generator.h"
@@ -146,7 +146,7 @@ void InitializeCommon(Platform* platform, mojo::Binder
   CrashMemoryMetricsReporterImpl::Instance();
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_MACOSX) || \
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_MACOSX) || defined(OS_BSD) || \
     defined(OS_WIN)
   // Initialize UserLevelMemoryPressureSignalGenerator so it starts monitoring.
   if (UserLevelMemoryPressureSignalGenerator::Enabled())
