--- include/steam/steamtypes.h.orig	2021-06-15 12:21:37 UTC
+++ include/steam/steamtypes.h
@@ -24,7 +24,7 @@ typedef unsigned char uint8;
 	#define POSIX 1
 #endif
 
-#if defined(__x86_64__) || defined(_WIN64) || defined(__aarch64__) || defined(__s390x__)
+#if defined(__x86_64__) || defined(_WIN64) || defined(__aarch64__) || defined(__s390x__) || defined(__powerpc64__) || defined(__riscv)
 #define X64BITS
 #endif
 
