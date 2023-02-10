--- third_party/blink/renderer/controller/blink_initializer.cc.orig	2023-01-17 19:19:00 UTC
+++ third_party/blink/renderer/controller/blink_initializer.cc
@@ -73,12 +73,12 @@
 #include "third_party/blink/renderer/controller/oom_intervention_impl.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/controller/memory_usage_monitor_posix.h"
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/controller/highest_pmf_reporter.h"
 #include "third_party/blink/renderer/controller/user_level_memory_pressure_signal_generator.h"
 #endif
@@ -226,7 +226,7 @@ void BlinkInitializer::RegisterInterfaces(mojo::Binder
       main_thread_task_runner);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   binders.Add<mojom::blink::MemoryUsageMonitorLinux>(
       ConvertToBaseRepeatingCallback(
           CrossThreadBindRepeating(&MemoryUsageMonitorPosix::Bind)),
@@ -259,7 +259,7 @@ void BlinkInitializer::RegisterMemoryWatchers() {
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Initialize UserLevelMemoryPressureSignalGenerator so it starts monitoring.
   UserLevelMemoryPressureSignalGenerator::Initialize(main_thread_task_runner);
 
