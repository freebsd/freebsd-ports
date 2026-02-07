--- src/external/rocksdb/util/crc32c_arm64.cc.orig	2024-12-19 20:17:47.515662000 -0800
+++ src/external/rocksdb/util/crc32c_arm64.cc	2024-12-19 20:18:18.667266000 -0800
@@ -10,7 +10,7 @@
 #if defined(__linux__)
 #include <asm/hwcap.h>
 #endif
-#ifdef ROCKSDB_AUXV_GETAUXVAL_PRESENT
+#if defined(ROCKSDB_AUXV_GETAUXVAL_PRESENT) || defined(__FreeBSD__)
 #include <sys/auxv.h>
 #endif
 #ifndef HWCAP_CRC32
