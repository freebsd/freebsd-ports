--- libhb/nlmeans_x86.c.orig	2022-12-28 17:43:46.000000000 +0900
+++ libhb/nlmeans_x86.c	2022-12-30 15:25:11.147350000 +0900
@@ -10,7 +10,7 @@
 
 #include "handbrake/handbrake.h"     // needed for ARCH_X86
 
-#if defined(ARCH_X86)
+#if defined(ARCH_X86_64)
 
 #include <emmintrin.h>
 
