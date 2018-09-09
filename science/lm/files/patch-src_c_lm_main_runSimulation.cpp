--- src/c/lm/main/runSimulation.cpp.orig	2018-09-09 19:31:22 UTC
+++ src/c/lm/main/runSimulation.cpp
@@ -45,6 +45,9 @@
  */
 #if defined(MACOSX)
 #include <sys/sysctl.h>
+#elif defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #elif defined(LINUX)
 #include <sys/sysinfo.h>
 #endif
@@ -149,6 +152,9 @@ void runSolver(char *simulationFilename,
     size_t  physicalCpuCoresSize=sizeof(physicalCpuCores);
     sysctlbyname("hw.activecpu",&physicalCpuCores,&physicalCpuCoresSize,NULL,0);
     numberCpuCores = physicalCpuCores;
+#elif defined(__FreeBSD__)
+    size_t	len = sizeof(numberCpuCores);
+    sysctlbyname("hw.ncpu",&numberCpuCores,&len,NULL,0);
 #elif defined(LINUX)
     #ifdef ARM
         numberCpuCores = get_nprocs_conf();
