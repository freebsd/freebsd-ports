--- src/crc32c/crc32c_config.h.orig	2023-08-07 12:55:59 UTC
+++ src/crc32c/crc32c_config.h
@@ -12,7 +12,7 @@
 #define HAVE_BUILTIN_PREFETCH 1
 
 // Define to 1 if targeting X86 and the compiler has the _mm_prefetch intrinsic.
-#define HAVE_MM_PREFETCH 1
+#define HAVE_MM_PREFETCH 0
 
 // Define to 1 if targeting X86 and the compiler has the _mm_crc32_u{8,32,64}
 // intrinsics.
