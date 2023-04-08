--- multiarc/src/formats/7z/C/Sha256Opt.c.orig	2023-01-14 23:53:02 UTC
+++ multiarc/src/formats/7z/C/Sha256Opt.c
@@ -234,7 +234,8 @@ void MY_FAST_CALL Sha256_UpdateBlocks_HW(UInt32 state[
 
 #if defined(__clang__) || defined(__GNUC__)
   #ifdef MY_CPU_ARM64
-    #define ATTRIB_SHA __attribute__((__target__("+crypto")))
+    #define __ARM_FEATURE_SHA2
+    #define ATTRIB_SHA __attribute__((__target__("sha2")))
   #else
     #define ATTRIB_SHA __attribute__((__target__("fpu=crypto-neon-fp-armv8")))
   #endif
