--- lzma/C/CpuArch.c.orig	2024-01-24 11:26:34 UTC
+++ lzma/C/CpuArch.c
@@ -762,10 +762,11 @@ BoolInt CPU_IsSupported_AES (void) { return APPLE_CRYP
 
 #include <sys/auxv.h>
 
+#ifdef __linux__
 #define USE_HWCAP
+#endif
 
 #ifdef USE_HWCAP
-
 #include <asm/hwcap.h>
 
   #define MY_HWCAP_CHECK_FUNC_2(name1, name2) \
