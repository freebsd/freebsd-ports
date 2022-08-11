--- fat-arm64.c.orig	2022-07-27 19:23:20 UTC
+++ fat-arm64.c
@@ -50,6 +50,9 @@
 # include <sys/sysctl.h>
 # include <machine/cpu.h>
 # include <machine/armreg.h>
+#elif defined(__FreeBSD__)
+#  define USE_GETAUXVAL 1
+#  include <sys/auxv.h>
 #endif
 
 #include "nettle-types.h"
@@ -117,7 +120,14 @@ get_arm64_features (struct arm64_features *features)
   else
     {
 #if USE_GETAUXVAL
+#if defined (__FreeBSD__)
+    unsigned long hwcap;
+    if(elf_aux_info(AT_HWCAP, &hwcap, sizeof(unsigned long)) != 0) {
+        hwcap = 0;
+    }
+#else
       unsigned long hwcap = getauxval(AT_HWCAP);
+#endif
       features->have_aes
 	= ((hwcap & (HWCAP_ASIMD | HWCAP_AES)) == (HWCAP_ASIMD | HWCAP_AES));
       features->have_pmull
