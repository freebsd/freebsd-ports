Index: programs/Xserver/hw/xfree86/drivers/ati/radeon_cursor.c
===================================================================
RCS file: /cvs/xc/programs/Xserver/hw/xfree86/drivers/ati/radeon_cursor.c,v
retrieving revision 1.23
diff -p -u -r1.23 radeon_cursor.c
--- programs/Xserver/hw/xfree86/drivers/ati/radeon_cursor.c	2003/02/24 20:34:55	1.23
+++ programs/Xserver/hw/xfree86/drivers/ati/radeon_cursor.c	2003/04/03 01:19:29
@@ -370,7 +370,7 @@ static void RADEONLoadCursorARGB (ScrnIn
     }
 
     if (info->IsSecondary || info->Clone) {
-	save2 = INREG(RADEON_CRTC_GEN_CNTL) & ~(CARD32) (3 << 20);
+	save2 = INREG(RADEON_CRTC2_GEN_CNTL) & ~(CARD32) (3 << 20);
 	save2 |= (CARD32) (2 << 20);
 	OUTREG(RADEON_CRTC2_GEN_CNTL, save2 & (CARD32)~RADEON_CRTC2_CUR_EN);
     }
