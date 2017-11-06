--- src/scfb_driver.c.orig	2014-07-19 22:22:29 UTC
+++ src/scfb_driver.c
@@ -55,7 +55,6 @@
 #include "xf86Priv.h"
 
 #include "mipointer.h"
-#include "mibstore.h"
 #include "micmap.h"
 #include "colormapst.h"
 #include "xf86cmap.h"
@@ -80,6 +79,8 @@
 #include "xf86xv.h"
 #endif
 
+#include "compat-api.h"
+
 #undef	DEBUG
 #define	DEBUG	1
 
@@ -101,15 +102,15 @@ static const OptionInfoRec * ScfbAvailab
 static void ScfbIdentify(int);
 static Bool ScfbProbe(DriverPtr, int);
 static Bool ScfbPreInit(ScrnInfoPtr, int);
-static Bool ScfbScreenInit(int, ScreenPtr, int, char **);
-static Bool ScfbCloseScreen(int, ScreenPtr);
+static Bool ScfbScreenInit(SCREEN_INIT_ARGS_DECL);
+static Bool ScfbCloseScreen(CLOSE_SCREEN_ARGS_DECL);
 static void *ScfbWindowLinear(ScreenPtr, CARD32, CARD32, int, CARD32 *,
 			      void *);
-static void ScfbPointerMoved(int, int, int);
-static Bool ScfbEnterVT(int, int);
-static void ScfbLeaveVT(int, int);
-static Bool ScfbSwitchMode(int, DisplayModePtr, int);
-static int ScfbValidMode(int, DisplayModePtr, Bool, int);
+static void ScfbPointerMoved(SCRN_ARG_TYPE, int, int);
+static Bool ScfbEnterVT(VT_FUNC_ARGS_DECL);
+static void ScfbLeaveVT(VT_FUNC_ARGS_DECL);
+static Bool ScfbSwitchMode(SWITCH_MODE_ARGS_DECL);
+static int ScfbValidMode(SCRN_ARG_TYPE, DisplayModePtr, Bool, int);
 static void ScfbLoadPalette(ScrnInfoPtr, int, int *, LOCO *, VisualPtr);
 static Bool ScfbSaveScreen(ScreenPtr, int);
 static void ScfbSave(ScrnInfoPtr);
@@ -231,7 +232,7 @@ typedef struct {
 	void *			shadow;
 	CloseScreenProcPtr	CloseScreen;
 	CreateScreenResourcesProcPtr CreateScreenResources;
-	void			(*PointerMoved)(int, int, int);
+	void			(*PointerMoved)(SCRN_ARG_TYPE, int, int);
 	EntityInfoPtr		pEnt;
 
 #ifdef XFreeXDGA
@@ -302,7 +303,7 @@ scfb_mmap(size_t len, off_t off, int fd)
 		mapaddr = NULL;
 	}
 #if DEBUG
-	ErrorF("mmap returns: addr %p len 0x%x, fd %d, off %x\n", mapaddr, mapsize, fd, off);
+	ErrorF("mmap returns: addr %p len 0x%x, fd %d, off %lx\n", mapaddr, mapsize, fd, off);
 #endif
 	return mapaddr;
 }
@@ -314,6 +315,7 @@ ScfbProbe(DriverPtr drv, int flags)
        	GDevPtr *devSections;
 	int numDevSections;
 	const char *dev;
+	struct fbtype fb;
 	Bool foundScreen = FALSE;
 
 	TRACE("probe start");
@@ -330,7 +332,8 @@ ScfbProbe(DriverPtr drv, int flags)
 	for (i = 0; i < numDevSections; i++) {
 		ScrnInfoPtr pScrn = NULL;
 		dev = xf86FindOptionValue(devSections[i]->options, "device");
-		if ((fd = xf86Info.consoleFd) >= 0) {
+		if ((fd = xf86Info.consoleFd) >= 0 &&
+		    ioctl(fd, FBIOGTYPE, &fb) != -1) {
 			entity = xf86ClaimFbSlot(drv, 0, devSections[i], TRUE);
 			pScrn = xf86ConfigFbEntity(NULL,0,entity,
 						   NULL,NULL,NULL,NULL);
@@ -366,8 +369,8 @@ ScfbPreInit(ScrnInfoPtr pScrn, int flags
 	struct fbtype fb;
 	int default_depth, wstype;
 	const char *dev;
-	char *mod = NULL, *s;
-	const char *reqSym = NULL;
+	char *mod = NULL;
+	const char *reqSym = NULL, *s;
 	Gamma zeros = {0.0, 0.0, 0.0};
 	DisplayModePtr mode;
 
@@ -633,9 +636,9 @@ ScfbShadowInit(ScreenPtr pScreen)
 }
 
 static Bool
-ScfbScreenInit(int scrnIndex, ScreenPtr pScreen, int argc, char **argv)
+ScfbScreenInit(SCREEN_INIT_ARGS_DECL)
 {
-	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
+	ScrnInfoPtr pScrn = xf86ScreenToScrn(pScreen);
 	ScfbPtr fPtr = SCFBPTR(pScrn);
 	VisualPtr visual;
 	int ret, flags, ncolors;
@@ -792,7 +795,7 @@ ScfbScreenInit(int scrnIndex, ScreenPtr 
 				   "RENDER extension initialisation failed.");
 	}
 	if (fPtr->shadowFB && !ScfbShadowInit(pScreen)) {
-		xf86DrvMsg(scrnIndex, X_ERROR,
+		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
 		    "shadow framebuffer initialization failed\n");
 		return FALSE;
 	}
@@ -801,20 +804,19 @@ ScfbScreenInit(int scrnIndex, ScreenPtr 
 	if (!fPtr->rotate)
 		ScfbDGAInit(pScrn, pScreen);
 	else
-		xf86DrvMsg(scrnIndex, X_INFO, "Rotated display, "
+		xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Rotated display, "
 		    "disabling DGA\n");
 #endif
 	if (fPtr->rotate) {
-		xf86DrvMsg(scrnIndex, X_INFO, "Enabling Driver Rotation, "
+		xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Enabling Driver Rotation, "
 		    "disabling RandR\n");
 		xf86DisableRandR();
 		if (pScrn->bitsPerPixel == 24)
-			xf86DrvMsg(scrnIndex, X_WARNING,
+			xf86DrvMsg(pScrn->scrnIndex, X_WARNING,
 			    "Rotation might be broken in 24 bpp\n");
 	}
 
 	xf86SetBlackWhitePixels(pScreen);
-	miInitializeBackingStore(pScreen);
 	xf86SetBackingStore(pScreen);
 
 	/* Software cursor. */
@@ -858,9 +860,9 @@ ScfbScreenInit(int scrnIndex, ScreenPtr 
 }
 
 static Bool
-ScfbCloseScreen(int scrnIndex, ScreenPtr pScreen)
+ScfbCloseScreen(CLOSE_SCREEN_ARGS_DECL)
 {
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	ScrnInfoPtr pScrn = xf86ScreenToScrn(pScreen);
 	PixmapPtr pPixmap;
 	ScfbPtr fPtr = SCFBPTR(pScrn);
 
@@ -892,7 +894,7 @@ ScfbCloseScreen(int scrnIndex, ScreenPtr
 	/* Unwrap CloseScreen. */
 	pScreen->CloseScreen = fPtr->CloseScreen;
 	TRACE_EXIT("ScfbCloseScreen");
-	return (*pScreen->CloseScreen)(scrnIndex, pScreen);
+	return (*pScreen->CloseScreen)(CLOSE_SCREEN_ARGS);
 }
 
 static void *
@@ -907,9 +909,9 @@ ScfbWindowLinear(ScreenPtr pScreen, CARD
 }
 
 static void
-ScfbPointerMoved(int index, int x, int y)
+ScfbPointerMoved(SCRN_ARG_TYPE arg, int x, int y)
 {
-    ScrnInfoPtr pScrn = xf86Screens[index];
+    SCRN_INFO_PTR(arg);
     ScfbPtr fPtr = SCFBPTR(pScrn);
     int newX, newY;
 
@@ -941,13 +943,13 @@ ScfbPointerMoved(int index, int x, int y
     }
 
     /* Pass adjusted pointer coordinates to wrapped PointerMoved function. */
-    (*fPtr->PointerMoved)(index, newX, newY);
+    (*fPtr->PointerMoved)(arg, newX, newY);
 }
 
 static Bool
-ScfbEnterVT(int scrnIndex, int flags)
+ScfbEnterVT(VT_FUNC_ARGS_DECL)
 {
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	SCRN_INFO_PTR(arg);
 
 	TRACE_ENTER("EnterVT");
 	pScrn->vtSema = TRUE;
@@ -956,20 +958,20 @@ ScfbEnterVT(int scrnIndex, int flags)
 }
 
 static void
-ScfbLeaveVT(int scrnIndex, int flags)
+ScfbLeaveVT(VT_FUNC_ARGS_DECL)
 {
 #if DEBUG
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	SCRN_INFO_PTR(arg);
 #endif
 
 	TRACE_ENTER("LeaveVT");
 }
 
 static Bool
-ScfbSwitchMode(int scrnIndex, DisplayModePtr mode, int flags)
+ScfbSwitchMode(SWITCH_MODE_ARGS_DECL)
 {
 #if DEBUG
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	SCRN_INFO_PTR(arg);
 #endif
 
 	TRACE_ENTER("SwitchMode");
@@ -978,10 +980,10 @@ ScfbSwitchMode(int scrnIndex, DisplayMod
 }
 
 static int
-ScfbValidMode(int scrnIndex, DisplayModePtr mode, Bool verbose, int flags)
+ScfbValidMode(SCRN_ARG_TYPE arg, DisplayModePtr mode, Bool verbose, int flags)
 {
 #if DEBUG
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	SCRN_INFO_PTR(arg);
 #endif
 
 	TRACE_ENTER("ValidMode");
@@ -1067,7 +1069,6 @@ static Bool
 ScfbDGASetMode(ScrnInfoPtr pScrn, DGAModePtr pDGAMode)
 {
 	DisplayModePtr pMode;
-	int scrnIdx = pScrn->pScreen->myNum;
 	int frameX0, frameY0;
 
 	if (pDGAMode) {
@@ -1081,9 +1082,9 @@ ScfbDGASetMode(ScrnInfoPtr pScrn, DGAMod
 		frameY0 = pScrn->frameY0;
 	}
 
-	if (!(*pScrn->SwitchMode)(scrnIdx, pMode, 0))
+	if (!(*pScrn->SwitchMode)(SWITCH_MODE_ARGS(pScrn, pMode)))
 		return FALSE;
-	(*pScrn->AdjustFrame)(scrnIdx, frameX0, frameY0, 0);
+	(*pScrn->AdjustFrame)(ADJUST_FRAME_ARGS(pScrn, frameX0, frameY0));
 
 	return TRUE;
 }
@@ -1091,7 +1092,7 @@ ScfbDGASetMode(ScrnInfoPtr pScrn, DGAMod
 static void
 ScfbDGASetViewport(ScrnInfoPtr pScrn, int x, int y, int flags)
 {
-	(*pScrn->AdjustFrame)(pScrn->pScreen->myNum, x, y, flags);
+	(*pScrn->AdjustFrame)(ADJUST_FRAME_ARGS(pScrn, x, y));
 }
 
 static int
