--- h3/minihwc/linhwc.c.orig	Sun Feb  2 00:56:37 2003
+++ h3/minihwc/linhwc.c	Fri Dec 24 21:34:38 2004
@@ -92,6 +92,7 @@
 static FxU32 calcBufferSize(FxU32 xres, FxU32 yres, FxBool tiled);
 static FxU32 calcBufferSizeInTiles(FxU32 xres, FxU32 yres);
 static FxU32 calcBufferHeightInTiles(FxU32 yres);
+static FxU32 hwcBufferLfbAddr(const hwcBoardInfo *bInfo, FxU32 physAddress);
 
 typedef struct envitem_t {
   char *env;
