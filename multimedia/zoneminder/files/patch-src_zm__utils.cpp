Partial application of upstream commit 78a10b6 to fix
armv7 support fix.

https://github.com/ZoneMinder/zoneminder/commit/78a10b6095b3759d341a1a336ac2b73a880871b4

--- src/zm_utils.cpp.orig	2021-12-10 22:36:30 UTC
+++ src/zm_utils.cpp
@@ -231,6 +231,8 @@ void HwCapsDetect() {
   unsigned long auxval = 0;
   elf_aux_info(AT_HWCAP, &auxval, sizeof(auxval));
   if (auxval & HWCAP_NEON) {
+  #else
+  {
   #error Unsupported OS.
   #endif
     Debug(1,"Detected ARM (AArch32) processor with Neon");
