# Correct types in a few format strings
#
--- src/tdfx_driver.c.orig	2015-02-22 21:25:54 UTC
+++ src/tdfx_driver.c
@@ -636,30 +636,30 @@ TDFXInitChips(ScrnInfoPtr pScrn)
     xf86DrvMsgVerb(pScrn->scrnIndex, X_INFO, 3,
 		   "TDFXInitChips: numchips = %d\n", pTDFX->numChips);
     xf86DrvMsgVerb(pScrn->scrnIndex, X_INFO, 3,
-		   "TDFXInitChips: cfgbits = 0x%08lx, initbits = 0x%08lx\n",
+		   "TDFXInitChips: cfgbits = 0x%08x, initbits = 0x%08x\n",
 		   cfgbits, initbits);
     xf86DrvMsgVerb(pScrn->scrnIndex, X_INFO, 3,
-		   "TDFXInitChips: mem0base = 0x%08lx, mem1base = 0x%08lx\n",
+		   "TDFXInitChips: mem0base = 0x%08x, mem1base = 0x%08x\n",
 		   mem0base, mem1base);
 
     mem0size = 32 * 1024 * 1024; /* Registers are always 32MB */
     mem1size = pScrn->videoRam * 1024 * 2; /* Linear mapping is 2x memory */
 
     xf86DrvMsgVerb(pScrn->scrnIndex, X_INFO, 3,
-		   "TDFXInitChips: mem0size = 0x%08lx, mem1size = 0x%08lx\n",
+		   "TDFXInitChips: mem0size = 0x%08x, mem1size = 0x%08x\n",
 		   mem0size, mem1size);
 
     mem0bits = TDFXSizeToCfg(mem0size);
     mem1bits = TDFXSizeToCfg(mem1size) << 4;
 
     xf86DrvMsgVerb(pScrn->scrnIndex, X_INFO, 3,
-		   "TDFXInitChips: mem0bits = 0x%08lx, mem1bits = 0x%08lx\n",
+		   "TDFXInitChips: mem0bits = 0x%08x, mem1bits = 0x%08x\n",
 		   mem0bits, mem1bits);
 
     cfgbits = (cfgbits & ~(0xFF)) | mem0bits | mem1bits;
 
     xf86DrvMsgVerb(pScrn->scrnIndex, X_INFO, 3,
-		   "TDFXInitChips: cfgbits = 0x%08lx\n", cfgbits);
+		   "TDFXInitChips: cfgbits = 0x%08x\n", cfgbits);
 
     for (i = 0; i < pTDFX->numChips; i++) {
 	PCI_WRITE_LONG(initbits | BIT(10), CFG_INIT_ENABLE, i);
