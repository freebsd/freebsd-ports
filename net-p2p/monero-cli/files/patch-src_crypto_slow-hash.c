--- src/crypto/slow-hash.c.orig	2022-03-30 06:28:17 UTC
+++ src/crypto/slow-hash.c
@@ -1102,7 +1102,7 @@ union cn_slow_hash_state
  * and moving between vector and regular registers stalls the pipeline.
  */
 #include <arm_neon.h>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <sys/auxv.h>
 #include <asm/hwcap.h>
 #endif
