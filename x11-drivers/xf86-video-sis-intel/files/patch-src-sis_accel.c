--- src/sis_accel.c.orig	2008-06-06 00:41:32.000000000 +0400
+++ src/sis_accel.c	2008-05-27 02:53:54.000000000 +0400
@@ -781,7 +781,7 @@
 
 #ifdef SIS_USE_EXA	/* ----------------------- EXA ----------------------- */
        if(pSiS->useEXA) {
-#if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0)
+#if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
 
 	  /* data */
 	  pSiS->EXADriverPtr->card.memoryBase = pSiS->FbBase;
@@ -795,7 +795,7 @@
 	     xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
 		"Not enough video RAM for offscreen memory manager. Xv disabled\n");
 	  }
-#if  XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(6,8,2,0,0)
+#if  XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(6,8,2,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
 	  pSiS->EXADriverPtr->card.offscreenByteAlign = 8;	/* src/dst: double quad word boundary */
 	  pSiS->EXADriverPtr->card.offscreenPitch = 1;
 #else
@@ -946,7 +946,7 @@
 						SiSScratchSave, pSiS);
 	  if(pSiS->exa_scratch) {
 	     pSiS->exa_scratch_next = pSiS->exa_scratch->offset;
-       #if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0)
+       #if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
              pSiS->EXADriverPtr->accel.UploadToScratch = SiSUploadToScratch;
        #else
              pSiS->EXADriverPtr->UploadToScratch = SiSUploadToScratch;
