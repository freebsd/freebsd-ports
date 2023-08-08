--- multiarc/src/formats/7z/C/AesOpt.c.orig	2023-01-14 23:53:02 UTC
+++ multiarc/src/formats/7z/C/AesOpt.c
@@ -537,7 +537,8 @@ VAES_COMPAT_STUB (AesCtr_Code_HW)
 
 #if defined(__clang__) || defined(__GNUC__)
   #ifdef MY_CPU_ARM64
-    #define ATTRIB_AES __attribute__((__target__("+crypto")))
+    #define __ARM_FEATURE_AES
+    #define ATTRIB_AES __attribute__((__target__("aes")))
   #else
     #define ATTRIB_AES __attribute__((__target__("fpu=crypto-neon-fp-armv8")))
   #endif
