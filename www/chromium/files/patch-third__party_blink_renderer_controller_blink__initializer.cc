--- third_party/blink/renderer/controller/blink_initializer.cc.orig	2020-05-13 18:40:34 UTC
+++ third_party/blink/renderer/controller/blink_initializer.cc
@@ -65,11 +65,11 @@
 #include "third_party/blink/renderer/controller/oom_intervention_impl.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
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
@@ -192,7 +192,7 @@ void BlinkInitializer::RegisterInterfaces(mojo::Binder
                   &CrashMemoryMetricsReporterImpl::Bind)),
               main_thread->GetTaskRunner());
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   binders.Add(ConvertToBaseRepeatingCallback(
                   CrossThreadBindRepeating(&MemoryUsageMonitorPosix::Bind)),
               main_thread->GetTaskRunner());
