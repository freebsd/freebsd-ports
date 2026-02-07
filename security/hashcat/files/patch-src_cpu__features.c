--- src/cpu_features.c.orig	2025-12-29 21:53:04 UTC
+++ src/cpu_features.c
@@ -16,17 +16,8 @@ int cpu_supports_avx512vl () { return 0; }
 int cpu_supports_avx512f ()  { return 0; }
 int cpu_supports_avx512vl () { return 0; }
 
-#elif defined(__riscv)
+#elif defined (__x86_64__) || defined (_M_X64) || defined (__i386__) || defined (_M_IX86)
 
-// TODO: Support RVV
-int cpu_supports_sse2 ()     { return 0; }
-int cpu_supports_ssse3 ()    { return 0; }
-int cpu_supports_xop ()      { return 0; }
-int cpu_supports_avx2 ()     { return 0; }
-int cpu_supports_avx512f ()  { return 0; }
-int cpu_supports_avx512vl () { return 0; }
-
-#else
 static inline void cpuid (u32 leaf, u32 subleaf, u32 *eax, u32 *ebx, u32 *ecx, u32 *edx)
 {
   __cpuid_count (leaf, subleaf, *eax, *ebx, *ecx, *edx);
@@ -140,6 +131,17 @@ int cpu_supports_avx512vl ()
 
   return (ebx & (1u << 31)) != 0;
 }
+
+#else
+
+// TODO: Support SIMD acceleration on other architectures
+int cpu_supports_sse2 ()     { return 0; }
+int cpu_supports_ssse3 ()    { return 0; }
+int cpu_supports_xop ()      { return 0; }
+int cpu_supports_avx2 ()     { return 0; }
+int cpu_supports_avx512f ()  { return 0; }
+int cpu_supports_avx512vl () { return 0; }
+
 #endif
 
 int cpu_chipset_test ()
