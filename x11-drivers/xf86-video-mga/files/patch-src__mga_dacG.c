--- ./src/mga_dacG.c.orig	2010-03-09 17:58:54.152419708 -0800
+++ ./src/mga_dacG.c	2010-03-09 17:58:54.157420208 -0800
@@ -211,6 +211,55 @@
 }
 
 static void
+MGAG200EHComputePLLParam(ScrnInfoPtr pScrn, long lFo, int *M, int *N, int *P)
+{
+    unsigned int ulComputedFo;
+    unsigned int ulFDelta;
+    unsigned int ulFPermitedDelta;
+    unsigned int ulFTmpDelta;
+    unsigned int ulTestP;
+    unsigned int ulTestM;
+    unsigned int ulTestN;
+    unsigned int ulVCOMax;
+    unsigned int ulVCOMin;
+    unsigned int ulPLLFreqRef;
+
+    ulVCOMax        = 800000;
+    ulVCOMin        = 400000;
+    ulPLLFreqRef    = 33333;
+
+    ulFDelta = 0xFFFFFFFF;
+    /* Permited delta is 0.5% as VESA Specification */
+    ulFPermitedDelta = lFo * 5 / 1000;  
+
+    /* Then we need to minimize the M while staying within 0.5% */
+    for (ulTestP = 16; ulTestP > 0; ulTestP>>= 1) {
+        if ((lFo * ulTestP) > ulVCOMax) continue;
+        if ((lFo * ulTestP) < ulVCOMin) continue;
+
+        for (ulTestM = 1; ulTestM <= 32; ulTestM++) {
+           for (ulTestN = 17; ulTestN <= 256; ulTestN++) {
+               ulComputedFo = (ulPLLFreqRef * ulTestN) / (ulTestM * ulTestP);
+               if (ulComputedFo > lFo)
+		           ulFTmpDelta = ulComputedFo - lFo;
+               else
+                   ulFTmpDelta = lFo - ulComputedFo;
+
+               if (ulFTmpDelta < ulFDelta) {
+                   ulFDelta = ulFTmpDelta;
+                   *M = (CARD8)(ulTestM - 1);
+                   *N = (CARD8)(ulTestN - 1);
+                   *P = (CARD8)(ulTestP - 1);
+               }
+
+               if ((lFo * ulTestP) >= 600000)
+                   *P |= 0x80;
+           }
+        }
+    }
+}
+
+static void
 MGAG200EVPIXPLLSET(ScrnInfoPtr pScrn, MGARegPtr mgaReg)
 {
     MGAPtr pMga = MGAPTR(pScrn);
@@ -483,6 +532,89 @@
     outMGAdac(MGA1064_GEN_IO_DATA, ucTmpData);
 }
 
+static void
+MGAG200EHPIXPLLSET(ScrnInfoPtr pScrn, MGARegPtr mgaReg)
+{
+    MGAPtr pMga = MGAPTR(pScrn);
+
+    unsigned long ulFallBackCounter, ulLoopCount, ulLockCheckIterations = 0, ulTempCount, ulVCount;
+    unsigned char ucTempByte, ucPixCtrl, ucPLLLocked = FALSE;
+    unsigned char ucM;
+    unsigned char ucN;
+    unsigned char ucP;
+    unsigned char ucS;
+
+    while(ulLockCheckIterations <= 32 && ucPLLLocked == FALSE)
+    {
+        // Set pixclkdis to 1
+        ucPixCtrl = inMGAdac(MGA1064_PIX_CLK_CTL);
+        ucPixCtrl |= MGA1064_PIX_CLK_CTL_CLK_DIS;
+        outMGAdac(MGA1064_PIX_CLK_CTL, ucPixCtrl);
+
+        // Select PLL Set C
+        ucTempByte = INREG8(MGAREG_MEM_MISC_READ);
+        ucTempByte |= 0x3<<2; //select MGA pixel clock
+        OUTREG8(MGAREG_MEM_MISC_WRITE, ucTempByte);
+
+        ucPixCtrl |= MGA1064_PIX_CLK_CTL_CLK_POW_DOWN;
+        ucPixCtrl &= ~0x80;
+        outMGAdac(MGA1064_PIX_CLK_CTL, ucPixCtrl);
+
+        // Wait 500 us
+        usleep(500);
+
+        // Program the Pixel PLL Register
+        outMGAdac(MGA1064_EH_PIX_PLLC_N, mgaReg->PllN);
+        outMGAdac(MGA1064_EH_PIX_PLLC_M, mgaReg->PllM);
+        outMGAdac(MGA1064_EH_PIX_PLLC_P, mgaReg->PllP);
+
+        // Wait 500 us
+        usleep(500);
+
+        // Select the pixel PLL by setting pixclksel to 1
+        ucTempByte = inMGAdac(MGA1064_PIX_CLK_CTL);
+        ucTempByte &= ~MGA1064_PIX_CLK_CTL_SEL_MSK;
+        ucTempByte |= MGA1064_PIX_CLK_CTL_SEL_PLL;
+        outMGAdac(MGA1064_PIX_CLK_CTL, ucTempByte);
+
+        // Reset dotclock rate bit.
+        OUTREG8(MGAREG_SEQ_INDEX, 1);
+        ucTempByte = INREG8(MGAREG_SEQ_DATA);
+        OUTREG8(MGAREG_SEQ_DATA, ucTempByte & ~0x8);
+
+        // Set pixclkdis to 0 and pixplldn to 0
+        ucTempByte = inMGAdac(MGA1064_PIX_CLK_CTL);
+        ucTempByte &= ~MGA1064_PIX_CLK_CTL_CLK_DIS;
+        ucTempByte &= ~MGA1064_PIX_CLK_CTL_CLK_POW_DOWN;
+        outMGAdac(MGA1064_PIX_CLK_CTL, ucTempByte);
+
+        // Poll VCount. If it increments twice inside 150us, 
+        // we assume that the PLL has locked.
+        ulLoopCount = 0;
+        ulVCount = INREG(MGAREG_VCOUNT);
+
+        while(ulLoopCount < 30 && ucPLLLocked == FALSE)
+        {
+            ulTempCount = INREG(MGAREG_VCOUNT);
+
+            if(ulTempCount < ulVCount)
+            {
+                ulVCount = 0;
+            }
+            if ((ucTempByte - ulVCount) > 2)
+            {
+                ucPLLLocked = TRUE;
+            }
+            else
+            {
+                usleep(5);
+            }
+            ulLoopCount++;
+        }
+        ulLockCheckIterations++;
+    }
+}
+
 /**
  * Calculate the PLL settings (m, n, p, s).
  *
@@ -631,6 +763,12 @@
 	    pReg->PllM = m;
 	    pReg->PllN = n;
 	    pReg->PllP = p;
+    } else if (pMga->is_G200EH) {
+	    MGAG200EHComputePLLParam(pScrn, f_out, &m, &n, &p);
+
+	    pReg->PllM = m;
+	    pReg->PllN = n;
+	    pReg->PllP = p;
         } else {
 	    /* Do the calculations for m, n, p and s */
 	    MGAGCalcClock( pScrn, f_out, &m, &n, &p, &s );
@@ -828,6 +966,15 @@
                 pReg->Option2 = 0x0000b000;
                 break;
 
+        case PCI_CHIP_MGAG200_EH_PCI:
+                pReg->DacRegs[MGA1064_MISC_CTL] =
+                    MGA1064_MISC_CTL_VGA8 |
+                    MGA1064_MISC_CTL_DAC_RAM_CS;
+
+                pReg->Option = 0x00000120;
+                pReg->Option2 = 0x0000b000;
+                break;
+
 	case PCI_CHIP_MGAG200:
 	case PCI_CHIP_MGAG200_PCI:
 	default:
@@ -1177,7 +1324,7 @@
 	      if (pMga->is_G200SE
 		  && ((i == 0x2C) || (i == 0x2D) || (i == 0x2E)))
 	         continue;
-	      if ( (pMga->is_G200EV || pMga->is_G200WB) &&
+	      if ( (pMga->is_G200EV || pMga->is_G200WB || pMga->is_G200EH) &&
 		   (i >= 0x44) && (i <= 0x4E))
 	         continue;
 
@@ -1218,6 +1365,8 @@
                MGAG200EVPIXPLLSET(pScrn, mgaReg);
            } else if (pMga->is_G200WB) {
                MGAG200WBPIXPLLSET(pScrn, mgaReg);
+           } else if (pMga->is_G200EH) {
+               MGAG200EHPIXPLLSET(pScrn, mgaReg);
            }
 );	/* MGA_NOT_HAL */
 #ifdef USEMGAHAL
@@ -1402,6 +1551,10 @@
             mgaReg->PllM = inMGAdac(MGA1064_EV_PIX_PLLC_M);
             mgaReg->PllN = inMGAdac(MGA1064_EV_PIX_PLLC_N);
             mgaReg->PllP = inMGAdac(MGA1064_EV_PIX_PLLC_P);
+        } else if (pMga->is_G200EH) {
+            mgaReg->PllM = inMGAdac(MGA1064_EH_PIX_PLLC_M);
+            mgaReg->PllN = inMGAdac(MGA1064_EH_PIX_PLLC_N);
+            mgaReg->PllP = inMGAdac(MGA1064_EH_PIX_PLLC_P);
         }
 
         mgaReg->PIXPLLCSaved = TRUE;
@@ -1584,6 +1737,7 @@
     { (1 << 0), (1 << 2) },
     { (1 << 4), (1 << 5) },
     { (1 << 0), (1 << 1) },  /* G200SE, G200EV and G200WB I2C bits */
+    { (1 << 1), (1 << 0) },  /* G200EH I2C bits */
 };
 
 
@@ -1596,6 +1750,8 @@
 
   if (pMga->is_G200SE || pMga->is_G200WB || pMga->is_G200EV)
     i2c_index = 3;
+  else if (pMga->is_G200EH)
+    i2c_index = 4;
   else
     i2c_index = 0;
 
@@ -1695,6 +1851,8 @@
 
         if (pMga->is_G200SE || pMga->is_G200WB || pMga->is_G200EV)
             i2c_index = 3;
+        else if (pMga->is_G200EH)
+            i2c_index = 4;
         else
             i2c_index = 0;
 
