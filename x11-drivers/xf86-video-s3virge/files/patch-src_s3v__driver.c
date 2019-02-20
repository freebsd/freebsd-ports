# Remove extra parenthesis to clear a style warning
#
--- src/s3v_driver.c.orig	2019-02-19 03:28:50.953742000 +0000
+++ src/s3v_driver.c	2019-02-19 03:29:09.119821000 +0000
@@ -2848,7 +2848,7 @@
 	  else
 	     new->CR67 = 0x50 | 0x4;                  /* 16bpp */
           }
-       else if ((pScrn->bitsPerPixel == 24) ) {
+       else if (pScrn->bitsPerPixel == 24) {
 	 new->CR67 = 0x74;              /* 24bpp, STREAMS */
 	  					/* Flag STREAMS proc. required */
           ps3v->NeedSTREAMS = TRUE;
