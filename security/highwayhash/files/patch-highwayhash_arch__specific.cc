--- highwayhash/arch_specific.cc.orig	2020-10-10 11:16:48 UTC
+++ highwayhash/arch_specific.cc
@@ -150,7 +150,7 @@ double DetectNominalClockRate() {
   }
  #elif __FreeBSD__
   size_t length = sizeof(freq);
-  sysctlbyname("dev.cpu.0.freq"), &freq, &length, NULL, 0);
+  sysctlbyname("dev.cpu.0.freq", &freq, &length, NULL, 0);
   freq *= 1E6;
   return freq;
 #endif
