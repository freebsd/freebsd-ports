--- programs/Xserver/hw/xfree86/drivers/ati/radeon_reg.h.orig	Mon Aug  9 15:37:22 2004
+++ programs/Xserver/hw/xfree86/drivers/ati/radeon_reg.h	Thu Jan 13 14:34:17 2005
@@ -803,7 +803,7 @@
 #       define RADEON_MC_MCLK_MAX_DYN_STOP_LAT (1<<12)
 #       define RADEON_IO_MCLK_MAX_DYN_STOP_LAT (1<<13)
 #       define RADEON_MC_MCLK_DYN_ENABLE    (1 << 14)
-#       define RADEON_IO_MCLK_DYN_ENABLE    (1 << 14)
+#       define RADEON_IO_MCLK_DYN_ENABLE    (1 << 15)
 #define RADEON_MDGPIO_A_REG                 0x01ac
 #define RADEON_MDGPIO_EN_REG                0x01b0
 #define RADEON_MDGPIO_MASK                  0x0198
