--- src/bridges/bridge_argon2id_reference.c.orig	2025-12-29 21:52:13 UTC
+++ src/bridges/bridge_argon2id_reference.c
@@ -18,10 +18,10 @@
 #include "core.c"
 #include "blake2/blake2b.c"
 
-#if defined(__riscv)
-#include "ref.c"
-#else
+#if defined (__x86_64__) || defined (_M_X64) || defined (__i386__) || defined (_M_IX86) || defined (__aarch64__) || defined (__arm64__)
 #include "opt.c"
+#else
+#include "ref.c"
 #endif
 
 // good: we can use this multiplier do reduce copy overhead to increase the guessing speed,
