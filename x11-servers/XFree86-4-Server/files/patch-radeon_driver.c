Index: programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c
===================================================================
RCS file: /cvs/xc/programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c,v
retrieving revision 1.118
retrieving revision 1.119
diff -u -u -r1.118 -r1.119
--- programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c	26 Feb 2004 04:25:29 -0000	1.118
+++ programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c	3 Mar 2004 18:11:43 -0000	1.119
@@ -1,4 +1,4 @@
-/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c,v 1.118 2004/02/26 04:25:29 martin Exp $ */
+/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c,v 1.119 2004/03/03 18:11:43 dawes Exp $ */
 /*
  * Copyright 2000 ATI Technologies Inc., Markham, Ontario, and
  *                VA Linux Systems Inc., Fremont, California.
@@ -7031,12 +7031,79 @@
     RADEONFreeRec(pScrn);
 }
 
+/*
+ * Powering done DAC, needed for DPMS problem with ViewSonic P817 (or its variant).
+ *
+ * Note for current DAC mapping when calling this function:
+ * For most of cards:
+ * single CRT:  Driver doesn't change the existing CRTC->DAC mapping, 
+ *              CRTC1 could be driving either DAC or both DACs.
+ * CRT+CRT:     CRTC1->TV DAC, CRTC2->Primary DAC
+ * DFP/LCD+CRT: CRTC2->TV DAC, CRTC2->Primary DAC.
+ * Some boards have two DACs reversed or don't even have a primary DAC,
+ * this is reflected in pRADEONEnt->ReversedDAC. And radeon 7200 doesn't 
+ * have a second DAC.
+ * It's kind of messy, we'll need to redo DAC mapping part some day.
+ */
+static void RADEONDacPowerSet(ScrnInfoPtr pScrn, Bool IsOn, Bool IsPrimaryDAC)
+{
+    RADEONInfoPtr  info       = RADEONPTR(pScrn);
+    unsigned char *RADEONMMIO = info->MMIO;
+
+    if (IsPrimaryDAC) {
+	CARD32 dac_cntl;
+	CARD32 dac_macro_cntl = 0;
+	dac_cntl = INREG(RADEON_DAC_CNTL);
+	if ((!info->IsMobility) || (info->ChipFamily == CHIP_FAMILY_RV350)) 
+	    dac_macro_cntl = INREG(RADEON_DAC_MACRO_CNTL);
+	if (IsOn) {
+	    dac_cntl &= ~RADEON_DAC_PDWN;
+	    dac_macro_cntl &= ~(RADEON_DAC_PDWN_R |
+				RADEON_DAC_PDWN_G |
+				RADEON_DAC_PDWN_B);
+	} else {
+	    dac_cntl |= RADEON_DAC_PDWN;
+	    dac_macro_cntl |= (RADEON_DAC_PDWN_R |
+			       RADEON_DAC_PDWN_G |
+			       RADEON_DAC_PDWN_B);
+	}
+	OUTREG(RADEON_DAC_CNTL, dac_cntl);
+	if ((!info->IsMobility) || (info->ChipFamily == CHIP_FAMILY_RV350)) 
+	    OUTREG(RADEON_DAC_MACRO_CNTL, dac_macro_cntl);
+    } else {
+	if (info->ChipFamily != CHIP_FAMILY_R200) {
+	    CARD32 tv_dac_cntl = INREG(RADEON_TV_DAC_CNTL);
+	    if (IsOn) {
+		tv_dac_cntl &= ~(RADEON_TV_DAC_RDACPD |
+				 RADEON_TV_DAC_GDACPD |
+				 RADEON_TV_DAC_BDACPD |
+				 RADEON_TV_DAC_BGSLEEP);
+	    } else {
+		tv_dac_cntl |= (RADEON_TV_DAC_RDACPD |
+				RADEON_TV_DAC_GDACPD |
+				RADEON_TV_DAC_BDACPD |
+				RADEON_TV_DAC_BGSLEEP);
+	    }
+	    OUTREG(RADEON_TV_DAC_CNTL, tv_dac_cntl);
+	} else {
+	    CARD32 fp2_gen_cntl = INREG(RADEON_FP2_GEN_CNTL);
+	    if (IsOn) {
+		fp2_gen_cntl |= RADEON_FP2_DV0_EN;
+	    } else {
+		fp2_gen_cntl &= ~RADEON_FP2_DV0_EN;
+	    }
+	    OUTREG(RADEON_FP2_GEN_CNTL, fp2_gen_cntl);
+	}
+    }
+}
+
 /* Sets VESA Display Power Management Signaling (DPMS) Mode */
 static void RADEONDisplayPowerManagementSet(ScrnInfoPtr pScrn,
 					    int PowerManagementMode,
 					    int flags)
 {
     RADEONInfoPtr  info       = RADEONPTR(pScrn);
+    RADEONEntPtr pRADEONEnt   = RADEONEntPriv(pScrn);
     unsigned char *RADEONMMIO = info->MMIO;
 
 #ifdef XF86DRI
@@ -7055,8 +7122,6 @@
 				     RADEON_CRTC2_VSYNC_DIS |
 				     RADEON_CRTC2_HSYNC_DIS);
 
-	/* TODO: additional handling for LCD ? */
-
 	switch (PowerManagementMode) {
 	case DPMSModeOn:
 	    /* Screen: On; HSync: On, VSync: On */
@@ -7123,13 +7188,19 @@
 		    if (info->ChipFamily >= CHIP_FAMILY_R200) {
 			OUTREGP (RADEON_FP2_GEN_CNTL, RADEON_FP2_DV0_EN, ~RADEON_FP2_DV0_EN);
 		    }
+		} else if (info->DisplayType == MT_CRT) {
+		    RADEONDacPowerSet(pScrn, TRUE, !pRADEONEnt->ReversedDAC);
 		}
 	    } else {
-		if ((info->Clone) && (info->CloneType == MT_DFP)) {
-		    OUTREGP (RADEON_FP2_GEN_CNTL, 0, ~RADEON_FP2_BLANK_EN);
-		    OUTREGP (RADEON_FP2_GEN_CNTL, RADEON_FP2_ON, ~RADEON_FP2_ON);
-		    if (info->ChipFamily >= CHIP_FAMILY_R200) {
-			OUTREGP (RADEON_FP2_GEN_CNTL, RADEON_FP2_DV0_EN, ~RADEON_FP2_DV0_EN);
+		if (info->Clone) {
+		    if (info->CloneType == MT_DFP) {
+			OUTREGP (RADEON_FP2_GEN_CNTL, 0, ~RADEON_FP2_BLANK_EN);
+			OUTREGP (RADEON_FP2_GEN_CNTL, RADEON_FP2_ON, ~RADEON_FP2_ON);
+			if (info->ChipFamily >= CHIP_FAMILY_R200) {
+			    OUTREGP (RADEON_FP2_GEN_CNTL, RADEON_FP2_DV0_EN, ~RADEON_FP2_DV0_EN);
+			}
+		    } else if (info->CloneType == MT_CRT) {
+			RADEONDacPowerSet(pScrn, TRUE, !pRADEONEnt->ReversedDAC);
 		    }
 		}
 		if (info->DisplayType == MT_DFP) {
@@ -7140,6 +7211,14 @@
 		    OUTREGP (RADEON_LVDS_GEN_CNTL, RADEON_LVDS_BLON, ~RADEON_LVDS_BLON);
 		    usleep (info->PanelPwrDly * 1000);
 		    OUTREGP (RADEON_LVDS_GEN_CNTL, RADEON_LVDS_ON, ~RADEON_LVDS_ON);
+		} else if (info->DisplayType == MT_CRT) {
+		    if ((pRADEONEnt->HasSecondary) || info->Clone) {
+			RADEONDacPowerSet(pScrn, TRUE, pRADEONEnt->ReversedDAC);
+		    } else {
+			RADEONDacPowerSet(pScrn, TRUE, TRUE);
+			if (info->HasCRTC2)
+			    RADEONDacPowerSet(pScrn, TRUE, FALSE);
+		    }
 		}
 	    }
 	} else if ((PowerManagementMode == DPMSModeOff) ||
@@ -7152,13 +7231,19 @@
 		    if (info->ChipFamily >= CHIP_FAMILY_R200) {
 			OUTREGP (RADEON_FP2_GEN_CNTL, 0, ~RADEON_FP2_DV0_EN);
 		    }
+		} else if (info->DisplayType == MT_CRT) {
+		    RADEONDacPowerSet(pScrn, FALSE, !pRADEONEnt->ReversedDAC);
 		}
 	    } else {
-		if ((info->Clone) && (info->CloneType == MT_DFP)) {
-		    OUTREGP (RADEON_FP2_GEN_CNTL, RADEON_FP2_BLANK_EN, ~RADEON_FP2_BLANK_EN);
-		    OUTREGP (RADEON_FP2_GEN_CNTL, 0, ~RADEON_FP2_ON);
-		    if (info->ChipFamily >= CHIP_FAMILY_R200) {
-			OUTREGP (RADEON_FP2_GEN_CNTL, 0, ~RADEON_FP2_DV0_EN);
+		if (info->Clone) {
+		    if(info->CloneType == MT_DFP) {
+			OUTREGP (RADEON_FP2_GEN_CNTL, RADEON_FP2_BLANK_EN, ~RADEON_FP2_BLANK_EN);
+			OUTREGP (RADEON_FP2_GEN_CNTL, 0, ~RADEON_FP2_ON);
+			if (info->ChipFamily >= CHIP_FAMILY_R200) {
+			    OUTREGP (RADEON_FP2_GEN_CNTL, 0, ~RADEON_FP2_DV0_EN);
+			}
+		    } else if (info->CloneType == MT_CRT) {
+			RADEONDacPowerSet(pScrn, FALSE, !pRADEONEnt->ReversedDAC);
 		    }
 		}
 		if (info->DisplayType == MT_DFP) {
@@ -7179,6 +7264,17 @@
 		    if (info->IsMobility || info->IsIGP) {
 			OUTPLL(RADEON_PIXCLKS_CNTL, tmpPixclksCntl);
 		    }
+		} else if (info->DisplayType == MT_CRT) {
+		    if ((pRADEONEnt->HasSecondary) || info->Clone) {
+			RADEONDacPowerSet(pScrn, FALSE, pRADEONEnt->ReversedDAC);
+		    } else {
+			/* single CRT, turning both DACs off, we don't really know 
+			 * which DAC is actually connected.
+			 */
+			RADEONDacPowerSet(pScrn, FALSE, TRUE);
+			if (info->HasCRTC2) /* don't apply this to old radeon (singel CRTC) card */
+			    RADEONDacPowerSet(pScrn, FALSE, FALSE);
+		    }
 		}
 	    }
 	}
