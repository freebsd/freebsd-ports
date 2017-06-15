# Correct a string that should be const
# Remove extra parenthesis to clear a style warning
#
--- src/s3v_driver.c.orig	2016-11-25 14:37:44 UTC
+++ src/s3v_driver.c
@@ -480,7 +480,7 @@ S3VPreInit(ScrnInfoPtr pScrn, int flags)
     ClockRangePtr clockRanges;
     char *mod = NULL;
     const char *reqSym = NULL;
-    char *s;
+    const char *s;
     
     unsigned char config1, config2, m, n, n1, n2, cr66 = 0;
     int mclk;
@@ -2850,7 +2850,7 @@ S3VModeInit(ScrnInfoPtr pScrn, DisplayMo
 	  else
 	     new->CR67 = 0x50 | 0x4;                  /* 16bpp */
           }
-       else if ((pScrn->bitsPerPixel == 24) ) {
+       else if (pScrn->bitsPerPixel == 24) {
 	 new->CR67 = 0x74;              /* 24bpp, STREAMS */
 	  					/* Flag STREAMS proc. required */
           ps3v->NeedSTREAMS = TRUE;
