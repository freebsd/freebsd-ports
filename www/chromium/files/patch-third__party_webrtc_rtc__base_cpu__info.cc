--- third_party/webrtc/rtc_base/cpu_info.cc.orig	2025-09-03 06:34:22 UTC
+++ third_party/webrtc/rtc_base/cpu_info.cc
@@ -22,7 +22,9 @@
 #elif defined(WEBRTC_FUCHSIA)
 #include <zircon/syscalls.h>
 #elif defined(WEBRTC_LINUX)
+#if !defined(WEBRTC_BSD)
 #include <features.h>
+#endif
 #include <stdlib.h>
 #include <string.h>  // IWYU pragma: keep
 #include <unistd.h>
@@ -33,7 +35,7 @@
 #define WEBRTC_GLIBC_PREREQ(a, b) 0
 #endif
 
-#if WEBRTC_GLIBC_PREREQ(2, 16)
+#if WEBRTC_GLIBC_PREREQ(2, 16) || defined(WEBRTC_BSD)
 #include <sys/auxv.h>  // IWYU pragma: keep
 #else
 #include <errno.h>
@@ -50,7 +52,7 @@
 #if defined(WEBRTC_ARCH_X86_FAMILY) && defined(_MSC_VER)
 #include <intrin.h>
 #endif
-#if defined(WEBRTC_ARCH_ARM_FAMILY) && defined(WEBRTC_LINUX)
+#if defined(WEBRTC_ARCH_ARM_FAMILY) && defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 #include <asm/hwcap.h>
 #endif
 
@@ -191,6 +193,9 @@ bool Supports(ISA instruction_set_architecture) {
     return 0 != (android_getCpuFeatures() & ANDROID_CPU_ARM_FEATURE_NEON);
 #elif defined(WEBRTC_LINUX)
     uint64_t hwcap = 0;
+#if defined(WEBRTC_BSD)
+    elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap));
+#else
 #if WEBRTC_GLIBC_PREREQ(2, 16)
     hwcap = getauxval(AT_HWCAP);
 #else
@@ -211,6 +216,7 @@ bool Supports(ISA instruction_set_architecture) {
       close(fd);
     }
 #endif  // WEBRTC_GLIBC_PREREQ(2, 16)
+#endif
 #if defined(__aarch64__)
     if ((hwcap & HWCAP_ASIMD) != 0) {
       return true;
