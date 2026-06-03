--- lib/arm/armcpu.c.orig	2026-01-07 15:27:46 UTC
+++ lib/arm/armcpu.c
@@ -107,6 +107,21 @@ ogg_uint32_t oc_cpu_flags_get(void){
   return flags;
 }
 
+#elif defined(__FreeBSD__)
+# include <sys/auxv.h>
+
+ogg_uint32_t oc_cpu_flags_get(void){
+  ogg_uint32_t  flags = OC_CPU_ARM_MEDIA; /* FreeBSD requires ARMv6 or newer */
+  unsigned long auxv = 0;
+
+  elf_aux_info(AT_HWCAP, &auxv, sizeof auxv);
+
+  if (auxv & HWCAP_EDSP) flags |= OC_CPU_ARM_EDSP;
+  if (auxv & HWCAP_NEON) flags |= OC_CPU_ARM_NEON;
+
+  return flags;
+}
+
 #elif defined(__riscos__)
 #include <kernel.h>
 #include <swis.h>
