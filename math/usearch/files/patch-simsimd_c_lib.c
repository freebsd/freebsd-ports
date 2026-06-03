--- simsimd/c/lib.c.orig	2026-02-27 20:37:49 UTC
+++ simsimd/c/lib.c
@@ -20,34 +20,34 @@
  *  - Windows - MSVC: everything except Sapphire Rapids and ARM SVE.
  *  - macOS - Apple Clang: only Arm NEON and x86 AVX2 Haswell extensions are available.
  */
-#if !defined(SIMSIMD_TARGET_NEON) && (defined(__APPLE__) || defined(__linux__))
+#if !defined(SIMSIMD_TARGET_NEON) && (defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__))
 #define SIMSIMD_TARGET_NEON 1
 #endif
-#if !defined(SIMSIMD_TARGET_SVE) && (defined(__linux__))
+#if !defined(SIMSIMD_TARGET_SVE) && (defined(__linux__) || defined(__FreeBSD__))
 #define SIMSIMD_TARGET_SVE 1
 #endif
-#if !defined(SIMSIMD_TARGET_SVE2) && (defined(__linux__))
+#if !defined(SIMSIMD_TARGET_SVE2) && (defined(__linux__) || defined(__FreeBSD__))
 #define SIMSIMD_TARGET_SVE2 1
 #endif
-#if !defined(SIMSIMD_TARGET_HASWELL) && (defined(_MSC_VER) || defined(__APPLE__) || defined(__linux__))
+#if !defined(SIMSIMD_TARGET_HASWELL) && (defined(_MSC_VER) || defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__))
 #define SIMSIMD_TARGET_HASWELL 1
 #endif
-#if !defined(SIMSIMD_TARGET_SKYLAKE) && (defined(_MSC_VER) || defined(__linux__))
+#if !defined(SIMSIMD_TARGET_SKYLAKE) && (defined(_MSC_VER) || defined(__linux__) || defined(__FreeBSD__))
 #define SIMSIMD_TARGET_SKYLAKE 1
 #endif
-#if !defined(SIMSIMD_TARGET_ICE) && (defined(_MSC_VER) || defined(__linux__))
+#if !defined(SIMSIMD_TARGET_ICE) && (defined(_MSC_VER) || defined(__linux__) || defined(__FreeBSD__))
 #define SIMSIMD_TARGET_ICE 1
 #endif
-#if !defined(SIMSIMD_TARGET_GENOA) && (defined(__linux__))
+#if !defined(SIMSIMD_TARGET_GENOA) && (defined(__linux__) || defined(__FreeBSD__))
 #define SIMSIMD_TARGET_GENOA 1
 #endif
-#if !defined(SIMSIMD_TARGET_SAPPHIRE) && (defined(__linux__))
+#if !defined(SIMSIMD_TARGET_SAPPHIRE) && (defined(__linux__) || defined(__FreeBSD__))
 #define SIMSIMD_TARGET_SAPPHIRE 1
 #endif
-#if !defined(SIMSIMD_TARGET_TURIN) && (defined(__linux__))
+#if !defined(SIMSIMD_TARGET_TURIN) && (defined(__linux__) || defined(__FreeBSD__))
 #define SIMSIMD_TARGET_TURIN 1
 #endif
-#if !defined(SIMSIMD_TARGET_SIERRA) && (defined(__linux__)) && 0 // TODO: Add target spec to GCC & Clang
+#if !defined(SIMSIMD_TARGET_SIERRA) && (defined(__linux__) || defined(__FreeBSD__)) && 0 // TODO: Add target spec to GCC & Clang
 #define SIMSIMD_TARGET_SIERRA 1
 #endif
 
