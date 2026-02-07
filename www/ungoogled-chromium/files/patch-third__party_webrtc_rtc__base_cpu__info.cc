--- third_party/webrtc/rtc_base/cpu_info.cc.orig	2025-09-10 13:22:16 UTC
+++ third_party/webrtc/rtc_base/cpu_info.cc
@@ -37,7 +37,9 @@
 #include <intrin.h>
 #endif
 #if defined(WEBRTC_ARCH_ARM_FAMILY) && defined(WEBRTC_LINUX)
+#if !defined(WEBRTC_BSD)
 #include <asm/hwcap.h>
+#endif
 #include <sys/auxv.h>
 #endif
 
@@ -178,7 +180,11 @@ bool Supports(ISA instruction_set_architecture) {
     return 0 != (android_getCpuFeatures() & ANDROID_CPU_ARM_FEATURE_NEON);
 #elif defined(WEBRTC_LINUX)
     uint64_t hwcap = 0;
+#if defined(WEBRTC_BSD)
+    elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap));
+#else
     hwcap = getauxval(AT_HWCAP);
+#endif
 #if defined(__aarch64__)
     if ((hwcap & HWCAP_ASIMD) != 0) {
       return true;
