--- ../common/LZMA/SDK/C/CpuArch.c.orig	2022-09-10 16:08:06.000000000 +0200
+++ ../common/LZMA/SDK/C/CpuArch.c	2022-09-21 09:40:04.461577000 +0200
@@ -421,10 +421,17 @@
 
 #ifdef USE_HWCAP
 
+#ifdef __linux__
 #include <asm/hwcap.h>
+#endif
 
+#ifdef __linux__
   #define MY_HWCAP_CHECK_FUNC_2(name1, name2) \
   BoolInt CPU_IsSupported_ ## name1() { return (getauxval(AT_HWCAP)  & (HWCAP_  ## name2)) ? 1 : 0; }
+#elif defined(__FreeBSD__)
+  #define MY_HWCAP_CHECK_FUNC_2(name1, name2) \
+  BoolInt CPU_IsSupported_ ## name1() { uint32_t hwcaps = 0; elf_aux_info(AT_HWCAP, &hwcaps, sizeof(hwcaps)); return (hwcaps  & (HWCAP_  ## name2)) ? 1 : 0; }
+#endif
 
 #ifdef MY_CPU_ARM64
   #define MY_HWCAP_CHECK_FUNC(name) \
