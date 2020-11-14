--- highwayhash/arch_specific.cc.orig	2020-11-14 08:32:41 UTC
+++ highwayhash/arch_specific.cc
@@ -174,7 +174,7 @@ double InvariantTicksPerSecond() {
 #elif __FreeBSD__
   static double cycles_per_second = 0;
   size_t length = sizeof(cycles_per_second);
-  sysctlbyname("kern.timecounter.tc.timebase.frequency", &cycles_per_second,
+  sysctlbyname("dev.cpu.0.freq", &cycles_per_second,
                &length, NULL, 0);
 #endif
   return cycles_per_second;
