--- ../../src/quant/quant.h.orig	Thu Dec  9 12:19:54 2004
+++ ../../src/quant/quant.h	Thu Dec  9 12:20:07 2004
@@ -82,7 +82,7 @@
 #endif
 
 #ifdef ARCH_IS_IA64
-quanth263_intraFunc dequant_intra_ia64;
+quant_intraFunc dequant_h263_intra_ia64;
 #endif
 
 /*****************************************************************************
