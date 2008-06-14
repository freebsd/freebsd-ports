--- src/sis300_accel.c.orig	2008-06-06 00:43:06.000000000 +0400
+++ src/sis300_accel.c	2008-05-27 02:53:37.000000000 +0400
@@ -1231,7 +1231,7 @@
 
 #ifdef SIS_USE_EXA	/* ----------------------- EXA ----------------------- */
 	   if(pSiS->useEXA) {
-#if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0)
+#if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
          
 	      if(pSiS->scrnOffset < 8192) {
 	         int obase = 0;
@@ -1253,7 +1253,7 @@
 			"Not enough video RAM for offscreen memory manager. Xv disabled\n");
 		 }
 		 
-#if  XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(6,8,2,0,0)
+#if  XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(6,8,2,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
                  pSiS->EXADriverPtr->card.offscreenByteAlign = 16;	/* src/dst: double quad word boundary */
 		 pSiS->EXADriverPtr->card.offscreenPitch = 4;	
 #else
@@ -1430,7 +1430,7 @@
 	      pSiS->exa_scratch = exaOffscreenAlloc(pScreen, 128 * 1024, 16, TRUE,
 						SiSScratchSave, pSiS);
     
-    #if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0)
+    #if  XORG_VERSION_CURRENT <= XORG_VERSION_NUMERIC(7,0,0,0,0) && XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(4,0,0,0,0)
               if(pSiS->exa_scratch) {
 		 pSiS->exa_scratch_next = pSiS->exa_scratch->offset;
 		 pSiS->EXADriverPtr->accel.UploadToScratch = SiSUploadToScratch;
