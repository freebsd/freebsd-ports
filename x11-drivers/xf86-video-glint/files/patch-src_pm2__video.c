# Correct a couple strings that should be const
#
--- src/pm2_video.c.orig	2013-02-07 07:55:44 UTC
+++ src/pm2_video.c
@@ -2593,7 +2593,7 @@ Permedia2ReadInput(int fd, pointer unuse
 }
 
 static Bool
-xvipcOpen(char *name, ScrnInfoPtr pScrn)
+xvipcOpen(const char *name, ScrnInfoPtr pScrn)
 {
     const char *osname;
 
@@ -3170,7 +3170,7 @@ Permedia2VideoInit(ScreenPtr pScreen)
 
     if (VideoIO ? xf86XVScreenInit(pScreen, &VARPtrs[0], 3) :
 		  xf86XVScreenInit(pScreen, &VARPtrs[2], 1)) {
-	char *s;
+	const char *s;
 
 	xvEncoding	= MAKE_ATOM(XV_ENCODING);
 	xvHue		= MAKE_ATOM(XV_HUE);
