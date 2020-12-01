--- base/util/memory_pressure/system_memory_pressure_evaluator.cc.orig	2020-11-16 14:03:42 UTC
+++ base/util/memory_pressure/system_memory_pressure_evaluator.cc
@@ -14,7 +14,7 @@
 #elif defined(OS_WIN)
 #include "base/util/memory_pressure/system_memory_pressure_evaluator_win.h"
 #include "base/win/windows_version.h"
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "base/util/memory_pressure/system_memory_pressure_evaluator_linux.h"
 #endif
 
@@ -45,7 +45,7 @@ SystemMemoryPressureEvaluator::CreateDefaultSystemEval
     evaluator->CreateOSSignalPressureEvaluator(monitor->CreateVoter());
   }
   return evaluator;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return std::make_unique<util::os_linux::SystemMemoryPressureEvaluator>(
       monitor->CreateVoter());
 #endif
