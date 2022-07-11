--- fat-arm64.c.orig	2022-06-02 17:57:15 UTC
+++ fat-arm64.c
@@ -46,6 +46,9 @@
 #  include <asm/hwcap.h>
 #  include <sys/auxv.h>
 # endif
+#elif defined(__FreeBSD__)
+#  define USE_GETAUXVAL 1
+#  include <sys/auxv.h>
 #endif
 
 #include "nettle-types.h"
@@ -113,7 +116,14 @@ get_arm64_features (struct arm64_features *features)
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
