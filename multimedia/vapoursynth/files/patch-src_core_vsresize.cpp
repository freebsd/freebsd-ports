--- src/core/vsresize.cpp.orig	2018-10-26 21:11:05 UTC
+++ src/core/vsresize.cpp
@@ -85,7 +85,7 @@ const std::unordered_map<std::string, zimg_cpu_type_e>
     { "f16c",      ZIMG_CPU_X86_F16C },
     { "avx2",      ZIMG_CPU_X86_AVX2 },
     { "avx512f",   ZIMG_CPU_X86_AVX512F },
-    { "avx512skl", ZIMG_CPU_X86_AVX512_SKL },
+    { "avx512skx", ZIMG_CPU_X86_AVX512_SKX },
 #endif
 };
 
