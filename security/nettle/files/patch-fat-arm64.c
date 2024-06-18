--- fat-arm64.c.orig	2024-06-16 15:27:54 UTC
+++ fat-arm64.c
@@ -51,6 +51,9 @@
 #if USE_GETAUXVAL
 # include <asm/hwcap.h>
 # include <sys/auxv.h>
+#elif defined(__FreeBSD__)
+#  define USE_GETAUXVAL 1
+#  include <sys/auxv.h>
 #elif defined(__OpenBSD__)
 # include <sys/sysctl.h>
 # include <machine/cpu.h>
@@ -134,7 +137,14 @@ get_arm64_features (struct arm64_features *features)
   else
     {
 #if USE_GETAUXVAL
+#if defined (__FreeBSD__)
+    unsigned long hwcap;
+    if(elf_aux_info(AT_HWCAP, &hwcap, sizeof(unsigned long)) != 0) {
+      hwcap = 0;
+    }
+#else
       unsigned long hwcap = getauxval(AT_HWCAP);
+#endif
       features->have_aes
 	= ((hwcap & (HWCAP_ASIMD | HWCAP_AES)) == (HWCAP_ASIMD | HWCAP_AES));
       features->have_pmull
