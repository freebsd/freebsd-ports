--- libhb/nlmeans_x86.c.orig	2017-10-05 21:17:34 UTC
+++ libhb/nlmeans_x86.c
@@ -10,7 +10,7 @@
 
 #include "hb.h"     // needed for ARCH_X86
 
-#if defined(ARCH_X86)
+#if defined(ARCH_X86) && defined(__X86_64)
 
 #include <emmintrin.h>
 
