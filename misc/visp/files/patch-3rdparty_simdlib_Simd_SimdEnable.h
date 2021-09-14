--- 3rdparty/simdlib/Simd/SimdEnable.h.orig	2021-09-14 12:31:27 UTC
+++ 3rdparty/simdlib/Simd/SimdEnable.h
@@ -51,7 +51,9 @@
 #include <fcntl.h>
 #include <sys/auxv.h>
 #if defined(SIMD_ARM_ENABLE) || defined(SIMD_ARM64_ENABLE)
+#if defined(__linux__)
 #include <asm/hwcap.h>
+#endif
 #endif
 #endif
 #endif
