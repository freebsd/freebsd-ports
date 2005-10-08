--- rastertokmlf.c.orig	Thu Sep  2 20:18:38 2004
+++ rastertokmlf.c	Sat Oct  8 21:21:41 2005
@@ -1339,6 +1339,7 @@
 	DWORD x, y, iShift;//, dwWidthInByte;
 	unsigned char bTmpCyan, bTmpMagenta, bTmpYellow, bTmpBlack, bit;
 	//int err = 0;
+	PHTHEADER pCHThdr, pMHThdr, pYHThdr, pKHThdr;
 
    /*
     * Make sure status messages are not buffered...
@@ -1572,10 +1573,10 @@
 		dwVert 	= header.cupsHeight;
       //dwWidthInByte = (dwHori + 7)/8;
 		
-		PHTHEADER pCHThdr = (PHTHEADER)pImage->pHT[0];
-		PHTHEADER pMHThdr = (PHTHEADER)pImage->pHT[1];
-		PHTHEADER pYHThdr = (PHTHEADER)pImage->pHT[2];
-		PHTHEADER pKHThdr = (PHTHEADER)pImage->pHT[3];
+		pCHThdr = (PHTHEADER)pImage->pHT[0];
+		pMHThdr = (PHTHEADER)pImage->pHT[1];
+		pYHThdr = (PHTHEADER)pImage->pHT[2];
+		pKHThdr = (PHTHEADER)pImage->pHT[3];
 
 		//pbSrc = pSrcBitmap;
 #ifdef CUPS_FLIP
