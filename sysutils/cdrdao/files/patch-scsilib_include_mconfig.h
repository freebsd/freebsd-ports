--- scsilib/include/mconfig.h.orig	2018-05-16 10:46:58 UTC
+++ scsilib/include/mconfig.h
@@ -72,12 +72,12 @@ extern "C" {
  * Types/Keywords
  */
 
-#if defined(__x86_64__) || defined(__ia64__) || defined(__powerpc64__) || defined(__s390x__) || defined(__sparc64__)
+#if defined(__aarch64__) || defined(__ia64__) || defined(__mips_n64) || defined(__powerpc64__) || (defined(__riscv) && (__riscv_xlen == 64)) || defined(__s390x__) || defined(__sparc64__) || defined(__x86_64__)
 #define SIZEOF_LONG_INT 8
 #define SIZEOF_CHAR_P 8
 #define SIZEOF_UNSIGNED_LONG_INT 8
 #define SIZEOF_UNSIGNED_CHAR_P 8
-#elif defined(__i386__) || defined(__powerpc__) || defined(__s390__) || defined(__sparc__)
+#elif defined(__arm__) || defined(__i386__) || defined(__mips__) || defined(__powerpc__) || (defined(__riscv) && (__riscv_xlen == 32)) || defined(__s390__) || defined(__sparc__)
 #define SIZEOF_LONG_INT 4
 #define SIZEOF_CHAR_P 4
 #define SIZEOF_UNSIGNED_LONG_INT 4
