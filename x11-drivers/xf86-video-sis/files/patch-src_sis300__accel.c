# Fix warning about shift of signed value
#
--- src/sis300_accel.c.orig	2015-08-29 23:34:25 UTC
+++ src/sis300_accel.c
@@ -100,7 +100,7 @@ SiSSetupForScreenToScreenCopy(ScrnInfoPt
 
 	SiSSetupDSTColorDepth(pSiS->DstColor);
 	SiSSetupSRCPitch(pSiS->scrnOffset)
-	SiSSetupDSTRect(pSiS->scrnOffset, -1)
+	SiSSetupDSTRect(pSiS->scrnOffset, -1U)
 
 	if(trans_color != -1) {
 	   SiSSetupROP(0x0A)
@@ -170,7 +170,7 @@ SiSSetupForSolidFill(ScrnInfoPtr pScrn,
 	   }
 	}
 	SiSSetupPATFG(color)
-	SiSSetupDSTRect(pSiS->scrnOffset, -1)
+	SiSSetupDSTRect(pSiS->scrnOffset, -1U)
 	SiSSetupDSTColorDepth(pSiS->DstColor);
 	SiSSetupROP(SiSGetPatternROP(rop))
 	/* SiSSetupCMDFlag(PATFG) - is zero */
@@ -342,7 +342,7 @@ SiSSetupForSolidLine(ScrnInfoPtr pScrn,
 
 	SiSSetupLineCount(1)
 	SiSSetupPATFG(color)
-	SiSSetupDSTRect(pSiS->scrnOffset, -1)
+	SiSSetupDSTRect(pSiS->scrnOffset, -1U)
 	SiSSetupDSTColorDepth(pSiS->DstColor);
 	SiSSetupROP(SiSGetPatternROP(rop))
 	SiSSetupCMDFlag(PATFG | LINE)
@@ -419,7 +419,7 @@ SiSSetupForDashedLine(ScrnInfoPtr pScrn,
 	SISPtr pSiS = SISPTR(pScrn);
 
 	SiSSetupLineCount(1)
-	SiSSetupDSTRect(pSiS->scrnOffset, -1)
+	SiSSetupDSTRect(pSiS->scrnOffset, -1U)
 	SiSSetupDSTColorDepth(pSiS->DstColor);
 	SiSSetupStyleLow(*pattern)
 	SiSSetupStyleHigh(*(pattern+4))
@@ -475,7 +475,7 @@ SiSSetupForMonoPatternFill(ScrnInfoPtr p
 {
 	SISPtr pSiS = SISPTR(pScrn);
 
-	SiSSetupDSTRect(pSiS->scrnOffset, -1)
+	SiSSetupDSTRect(pSiS->scrnOffset, -1U)
 	SiSSetupDSTColorDepth(pSiS->DstColor);
 	SiSSetupMONOPAT(patx,paty)
 	SiSSetupPATFG(fg)
@@ -593,7 +593,7 @@ SiSSetupForScreenToScreenColorExpand(Scr
 	SISPtr pSiS = SISPTR(pScrn);
 
 	SiSSetupDSTColorDepth(pSiS->DstColor)
-	SiSSetupDSTRect(pSiS->scrnOffset, -1)
+	SiSSetupDSTRect(pSiS->scrnOffset, -1U)
 	SiSSetupROP(SiSGetCopyROP(rop))
 	SiSSetupSRCFG(fg)
 	/* SiSSetupSRCXY(0,0) */
@@ -762,7 +762,7 @@ SiSSetupForScanlineCPUToScreenColorExpan
 	SiSSetupSRCXY(0,0);
 	SiSSetupROP(SiSGetCopyROP(rop));
 	SiSSetupSRCFG(fg);
-	SiSSetupDSTRect(pSiS->scrnOffset, -1);
+	SiSSetupDSTRect(pSiS->scrnOffset, -1U);
 	SiSSetupDSTColorDepth(pSiS->DstColor);
 	if(bg == -1) {
 	   SiSSetupCMDFlag(TRANSPARENT |
@@ -925,7 +925,7 @@ SiSPrepareSolid(PixmapPtr pPixmap, int a
 	dstbase = (CARD32)exaGetPixmapOffset(pPixmap) + HEADOFFSET;
 
 	SiSSetupPATFG(fg)
-	SiSSetupDSTRect(exaGetPixmapPitch(pPixmap), -1)
+	SiSSetupDSTRect(exaGetPixmapPitch(pPixmap), -1U)
 	SiSSetupDSTColorDepth(dstcol[pPixmap->drawable.bitsPerPixel >> 4]);
 	SiSSetupROP(SiSGetPatternROP(alu))
 	SiSSetupDSTBase(dstbase)
@@ -988,7 +988,7 @@ SiSPrepareCopy(PixmapPtr pSrcPixmap, Pix
 
 	SiSSetupDSTColorDepth(dstcol[pDstPixmap->drawable.bitsPerPixel >> 4]);
 	SiSSetupSRCPitch(exaGetPixmapPitch(pSrcPixmap))
-	SiSSetupDSTRect(exaGetPixmapPitch(pDstPixmap), -1)
+	SiSSetupDSTRect(exaGetPixmapPitch(pDstPixmap), -1U)
 
 	SiSSetupROP(SiSGetCopyROP(alu))
 
