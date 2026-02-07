--- codec/common/src/cpu.cpp.orig	2015-03-25 07:43:00 UTC
+++ codec/common/src/cpu.cpp
@@ -276,9 +276,17 @@ uint32_t WelsCPUFeatureDetect (int32_t* 
  * that NEON and all associated features are available. */
 
 uint32_t WelsCPUFeatureDetect (int32_t* pNumberOfLogicProcessors) {
-  return WELS_CPU_ARMv7 |
-         WELS_CPU_VFPv3 |
-         WELS_CPU_NEON;
+  int flags = 0;
+# if __ARM_ARCH >= 7
+  flags |= WELS_CPU_ARMv7;
+# endif
+# ifdef __ARM_VFPV3__
+  flags |= WELS_CPU_VFPv3;
+# endif
+# ifdef __ARM_NEON
+  flags |= WELS_CPU_NEON;
+# endif
+  return flags;
 }
 #endif
 #elif defined(HAVE_NEON_AARCH64)
