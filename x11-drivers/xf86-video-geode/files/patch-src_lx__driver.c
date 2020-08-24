--- src/lx_driver.c.orig	2020-08-24 20:15:55 UTC
+++ src/lx_driver.c
@@ -74,7 +74,7 @@
 
 extern OptionInfoRec LX_GeodeOptions[];
 
-unsigned char *XpressROMPtr;
+extern unsigned char *XpressROMPtr;
 
 static Bool
 LXSaveScreen(ScreenPtr pScrn, int mode)
