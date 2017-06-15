# Correct a string type that should be const
#
--- src/lg_driver.c.orig	2016-11-24 04:05:04 UTC
+++ src/lg_driver.c
@@ -332,7 +332,7 @@ LgPreInit(ScrnInfoPtr pScrn, int flags)
 	int i;
 	ClockRangePtr clockRanges;
 	int fbPCIReg, ioPCIReg;
-	char *s;
+	const char *s;
 
 	if (flags & PROBE_DETECT)  {
 	  cirProbeDDC( pScrn, xf86GetEntityInfo(pScrn->entityList[0])->index );
