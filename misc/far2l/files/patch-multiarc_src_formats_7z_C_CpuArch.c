--- multiarc/src/formats/7z/C/CpuArch.c.orig	2023-01-14 23:53:02 UTC
+++ multiarc/src/formats/7z/C/CpuArch.c
@@ -422,7 +422,16 @@ BoolInt CPU_IsSupported_AES (void) { return APPLE_CRYP
 
 #ifdef USE_HWCAP
 
+#ifdef __FreeBSD__
+static unsigned long getauxval(int aux)
+{
+  unsigned long auxval = 0;
+  elf_aux_info(aux, &auxval, sizeof(auxval));
+  return auxval;
+}
+#else
 #include <asm/hwcap.h>
+#endif
 
   #define MY_HWCAP_CHECK_FUNC_2(name1, name2) \
   BoolInt CPU_IsSupported_ ## name1() { return (getauxval(AT_HWCAP)  & (HWCAP_  ## name2)) ? 1 : 0; }
