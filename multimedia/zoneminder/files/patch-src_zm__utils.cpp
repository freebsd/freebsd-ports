--- src/zm_utils.cpp.orig	2021-11-28 23:56:36 UTC
+++ src/zm_utils.cpp
@@ -224,8 +224,9 @@ void HwCapsDetect() {
 #elif defined(__arm__)
   // ARM processor in 32bit mode
   // To see if it supports NEON, we need to get that information from the kernel
-  unsigned long auxval = getauxval(AT_HWCAP);
-  if (auxval & HWCAP_ARM_NEON) {
+  unsigned long auxval = 0;
+  elf_aux_info(AT_HWCAP, &auxval, sizeof(auxval));
+  if (auxval & HWCAP_NEON) {
     Debug(1,"Detected ARM (AArch32) processor with Neon");
     neonversion = 1;
   } else {
