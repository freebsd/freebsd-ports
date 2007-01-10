--- ../../src/quant/quant.h.orig	Wed Jan 10 22:31:55 2007
+++ ../../src/quant/quant.h	Wed Jan 10 22:33:43 2007
@@ -91,7 +91,7 @@
 #endif
 
 #ifdef ARCH_IS_IA64
-quant_intraFunc dequant_h263_intra_ia64
+quant_intraFunc dequant_h263_intra_ia64;
 #endif
 
 #ifdef ARCH_IS_PPC
