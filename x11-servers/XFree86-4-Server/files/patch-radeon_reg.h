Index: programs/Xserver/hw/xfree86/drivers/ati/radeon_reg.h
===================================================================
RCS file: /cvs/xc/programs/Xserver/hw/xfree86/drivers/ati/radeon_reg.h,v
retrieving revision 1.32
retrieving revision 1.33
diff -u -u -r1.32 -r1.33
--- programs/Xserver/hw/xfree86/drivers/ati/radeon_reg.h	19 Feb 2004 22:38:12 -0000	1.32
+++ programs/Xserver/hw/xfree86/drivers/ati/radeon_reg.h	3 Mar 2004 18:11:45 -0000	1.33
@@ -1,4 +1,4 @@
-/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/ati/radeon_reg.h,v 1.32 2004/02/19 22:38:12 tsi Exp $ */
+/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/ati/radeon_reg.h,v 1.33 2004/03/03 18:11:45 dawes Exp $ */
 /*
  * Copyright 2000 ATI Technologies Inc., Markham, Ontario, and
  *                VA Linux Systems Inc., Fremont, California.
@@ -401,11 +401,16 @@
 #       define RADEON_DAC_FORCE_DATA_SEL_MASK (3 << 6)
 #       define RADEON_DAC_FORCE_DATA_MASK   0x0003ff00
 #       define RADEON_DAC_FORCE_DATA_SHIFT  8
+#define RADEON_DAC_MACRO_CNTL               0x0d04
+#       define RADEON_DAC_PDWN_R            (1 << 16)
+#       define RADEON_DAC_PDWN_G            (1 << 17)
+#       define RADEON_DAC_PDWN_B            (1 << 18)
 #define RADEON_TV_DAC_CNTL                  0x088c
 #       define RADEON_TV_DAC_STD_MASK       0x0300
 #       define RADEON_TV_DAC_RDACPD         (1 <<  24)
 #       define RADEON_TV_DAC_GDACPD         (1 <<  25)
 #       define RADEON_TV_DAC_BDACPD         (1 <<  26)
+#       define RADEON_TV_DAC_BGSLEEP        (1 <<  26)
 #define RADEON_DISP_HW_DEBUG                0x0d14
 #       define RADEON_CRT2_DISP1_SEL        (1 <<  5)
 #define RADEON_DISP_OUTPUT_CNTL             0x0d64
