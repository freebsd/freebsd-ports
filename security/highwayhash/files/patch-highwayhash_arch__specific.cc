--- highwayhash/arch_specific.cc.orig	2020-09-22 06:18:43 UTC
+++ highwayhash/arch_specific.cc
@@ -24,8 +24,8 @@
 #if __GLIBC__
 #include <sys/platform/ppc.h>  // __ppc_get_timebase_freq
 #elif __FreeBSD__
-#include <sys/sysctl.h>
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #endif
 #endif
 
@@ -174,7 +174,7 @@ double InvariantTicksPerSecond() {
 #elif __FreeBSD__
   static double cycles_per_second = 0;
   size_t length = sizeof(cycles_per_second);
-  sysctlbyname("kern.timecounter.tc.timebase.frequency", &cycles_per_second,
+  sysctlbyname("dev.cpu.0.freq", &cycles_per_second,
                &length, NULL, 0);
 #endif
   return cycles_per_second;
