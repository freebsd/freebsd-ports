--- ./src/mga_reg.h.orig	2009-07-26 20:37:46.000000000 -0700
+++ ./src/mga_reg.h	2010-03-09 17:58:54.165420896 -0800
@@ -432,6 +432,11 @@
 #define MGA1064_EV_PIX_PLLC_N	0xb7
 #define MGA1064_EV_PIX_PLLC_P	0xb8
 
+/* Modified PLL for G200 EH */
+#define MGA1064_EH_PIX_PLLC_M   0xb6
+#define MGA1064_EH_PIX_PLLC_N   0xb7
+#define MGA1064_EH_PIX_PLLC_P   0xb8
+
 
 #define MGA1064_DISP_CTL        0x8a
 #define MGA1064_DISP_CTL_DAC1OUTSEL_MASK       0x01
