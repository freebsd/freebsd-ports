--- auxil/highwayhash/highwayhash/arch_specific.cc.orig	2021-03-23 17:45:40 UTC
+++ auxil/highwayhash/highwayhash/arch_specific.cc
@@ -150,7 +150,7 @@ double DetectNominalClockRate() {
   }
  #elif __FreeBSD__
   size_t length = sizeof(freq);
-  sysctlbyname("dev.cpu.0.freq"), &freq, &length, NULL, 0);
+  sysctlbyname("dev.cpu.0.freq", &freq, &length, NULL, 0);
   freq *= 1E6;
   return freq;
 #endif
