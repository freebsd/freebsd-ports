--- src/sis310_accel.c.orig	2007-05-02 05:12:57.000000000 +0400
+++ src/sis310_accel.c	2008-06-09 22:15:56.000000000 +0400
@@ -65,7 +65,7 @@
 #  define SIS_NEED_ARRAY
 #  undef SISNEWRENDER
 #  ifdef XORG_VERSION_CURRENT
-#   if XORG_VERSION_CURRENT > XORG_VERSION_NUMERIC(6,7,0,0,0)
+#   if (XORG_VERSION_CURRENT > XORG_VERSION_NUMERIC(6,7,0,0,0) || XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(4,0,0,0,0))
 #    define SISNEWRENDER
 #   endif
 #  endif
@@ -1099,13 +1099,13 @@
 
 	SiSOccpyCmdQue(pSiS);
 #ifdef SISVRAMQ
-	if(op > SiSRenderOpsMAX) return FALSE;
-	if(!SiSRenderOps[op])    return FALSE;
+	if(op > SiSRenderOpsMAX) {SiSReleaseCmdQue(pSiS); return FALSE;}
+	if(!SiSRenderOps[op]) {SiSReleaseCmdQue(pSiS); return FALSE;}
 #else
-	if(op != PictOpOver) return FALSE;
+	if(op != PictOpOver) {SiSReleaseCmdQue(pSiS); return FALSE;}
 #endif
 
-	if((width > 2048) || (height > 2048)) return FALSE;
+	if((width > 2048) || (height > 2048)) { SiSReleaseCmdQue(pSiS); return FALSE;}
 
 	pitch = (width + 31) & ~31;
 	sizeNeeded = (pitch << bppshift) * height;
@@ -1115,8 +1115,10 @@
 		texType, op, width, height, texPitch, sizeNeeded, sbpp, sbppshift, bppshift);
 #endif
 
-	if(!SiSAllocateLinear(pScrn, (sizeNeeded + sbpp - 1) >> sbppshift))
+	if(!SiSAllocateLinear(pScrn, (sizeNeeded + sbpp - 1) >> sbppshift)) {
+	   SiSReleaseCmdQue(pSiS);
 	   return FALSE;
+	}
 
 	width <<= bppshift;  /* -> bytes (for engine and memcpy) */
 	pitch <<= bppshift;  /* -> bytes */
@@ -1159,6 +1161,7 @@
 	   SiSSetupCMDFlag(ALPHA_BLEND | SRCVIDEO | A_PERPIXELALPHA)
 	   break;
 	default:
+	   SiSReleaseCmdQue(pSiS);
 	   return FALSE;
  	}
         SiSSyncWP
@@ -1463,11 +1466,11 @@
 
 	w = pSrc->drawable.width;
 
-#if  XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(6,8,2,0,0)
+#if  XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(6,8,2,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
 	dst_pitch = ((w * (pSrc->drawable.bitsPerPixel >> 3)) +
 		     pSiS->EXADriverPtr->card.offscreenPitch - 1) &
 		    ~(pSiS->EXADriverPtr->card.offscreenPitch - 1);
-#elif XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0)
+#elif XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
 	dst_pitch = ((w * (pSrc->drawable.bitsPerPixel >> 3)) +
 		     pSiS->EXADriverPtr->card.pixmapPitchAlign - 1) &
 		    ~(pSiS->EXADriverPtr->card.pixmapPitchAlign - 1);
@@ -1482,11 +1485,11 @@
 	if(size > pSiS->exa_scratch->size)
 	   return FALSE;
 
-#if  XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(6,8,2,0,0)
+#if  XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(6,8,2,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
 	pSiS->exa_scratch_next = (pSiS->exa_scratch_next +
 				  pSiS->EXADriverPtr->card.offscreenByteAlign - 1) &
 				  ~(pSiS->EXADriverPtr->card.offscreenByteAlign - 1);
-#elif  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0)
+#elif  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
 	pSiS->exa_scratch_next = (pSiS->exa_scratch_next +
 				  pSiS->EXADriverPtr->card.pixmapOffsetAlign - 1) &
 				  ~(pSiS->EXADriverPtr->card.pixmapOffsetAlign - 1);
@@ -1496,7 +1499,7 @@
 				  ~(pSiS->EXADriverPtr->pixmapOffsetAlign - 1);
 #endif
 
-#if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0)
+#if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
 	if(pSiS->exa_scratch_next + size >
 	   pSiS->exa_scratch->offset + pSiS->exa_scratch->size) {
 	   (pSiS->EXADriverPtr->accel.WaitMarker)(pSrc->drawable.pScreen, 0);
@@ -1513,7 +1516,7 @@
 	memcpy(pDst, pSrc, sizeof(*pDst));
 	pDst->devKind = dst_pitch;
 
-#if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0)
+#if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
 	pDst->devPrivate.ptr = pSiS->EXADriverPtr->card.memoryBase + pSiS->exa_scratch_next;
 #else
 	pDst->devPrivate.ptr = pSiS->EXADriverPtr->memoryBase + pSiS->exa_scratch_next;
@@ -1755,7 +1758,7 @@
 
 #ifdef SIS_USE_EXA	/* ----------------------- EXA ----------------------- */
 	   if(pSiS->useEXA) {
-#if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0)
+#if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
 
 	      int obase = 0;
 
@@ -1776,7 +1779,7 @@
 			"Not enough video RAM for offscreen memory manager. Xv disabled\n");
 	      }
 
-#if  XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(6,8,2,0,0)
+#if  XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(6,8,2,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
 	      pSiS->EXADriverPtr->card.offscreenByteAlign = 16;	/* src/dst: double quad word boundary */
 	      pSiS->EXADriverPtr->card.offscreenPitch = 4;	/* pitch:   double word boundary      */
 #else
@@ -1945,7 +1948,7 @@
 						SiSScratchSave, pSiS);
 	      if(pSiS->exa_scratch) {
 		 pSiS->exa_scratch_next = pSiS->exa_scratch->offset;
-        #if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0)
+        #if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
 		 pSiS->EXADriverPtr->accel.UploadToScratch = SiSUploadToScratch;
 	#else
                  pSiS->EXADriverPtr->UploadToScratch = SiSUploadToScratch;
