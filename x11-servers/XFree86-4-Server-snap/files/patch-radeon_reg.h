--- programs/Xserver/hw/xfree86/drivers/ati/radeon_reg.h.orig	Fri Feb  7 10:08:59 2003
+++ programs/Xserver/hw/xfree86/drivers/ati/radeon_reg.h	Sat Apr 26 01:10:10 2003
@@ -879,7 +879,7 @@
 #       define RADEON_P2PLL_REF_DIV_MASK    0x03ff
 #       define RADEON_P2PLL_ATOMIC_UPDATE_R (1 << 15) /* same as _W */
 #       define RADEON_P2PLL_ATOMIC_UPDATE_W (1 << 15) /* same as _R */
-#       define R300_PPLL_REF_DIV_ACC_MASK   (0x3ff < 18)
+#       define R300_PPLL_REF_DIV_ACC_MASK   (0x3ff << 18)
 #       define R300_PPLL_REF_DIV_ACC_SHIFT  18
 #define RADEON_PALETTE_DATA                 0x00b4
 #define RADEON_PALETTE_30_DATA              0x00b8
