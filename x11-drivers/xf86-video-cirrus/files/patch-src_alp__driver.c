# Correct a string type that should be const
#
--- src/alp_driver.c.orig	2016-11-24 04:07:05 UTC
+++ src/alp_driver.c
@@ -468,7 +468,7 @@ AlpPreInit(ScrnInfoPtr pScrn, int flags)
 	int i;
 	int depth_flags;
 	ClockRangePtr clockRanges;
-	char *s;
+	const char *s;
  	xf86Int10InfoPtr pInt = NULL;
 
 	if (flags & PROBE_DETECT)  {
