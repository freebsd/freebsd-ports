--- inc/na/cmd.h.orig	Tue Aug 18 18:39:14 1998
+++ inc/na/cmd.h	Thu Sep 18 20:10:32 2003
@@ -1881,13 +1881,12 @@
         , { 0, 0, 0, V_BIG_BIRD_N, V_BIG_BIRD_N, 0, V_BIG_BIRD_N, V_PRIMATE_N }
 #endif
 },
-#ifndef NA
+/* XXXCDC: was ifndef NA, need this or indexs off by 1! */
 {ARPT_TTKILLC, DFE_CAT, DFE_ARPT_TTKILLC , B_GENERIC_CAT, CARDINAL_P, CNV_BYTE
 #ifdef NA
 	, { 0, 0, 0, 0, 0, 0, 0, 0 }
 #endif
 },
-#endif
 {FAIL_TO_CONNECT, DFE_CAT, DFE_FAIL_TO_CONNECT, B_GENERIC_CAT, CARDINAL_P, CNV_INT
 #ifdef NA
         , { 0, 0, 0, V_14_0_N, V_14_0_N, 0, 0, V_14_0_N }
