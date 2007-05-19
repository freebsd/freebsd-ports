--- hw/xfree86/common/xf86Config.c.orig	Fri Jun 23 12:32:32 2006
+++ hw/xfree86/common/xf86Config.c	Fri Jun 23 12:32:46 2006
@@ -1042,7 +1042,7 @@
     else
 	xf86Info.estimateSizesAggressively = 0;
 
-    xf86Info.aiglx = TRUE;
+    xf86Info.aiglx = FALSE;
     xf86Info.aiglxFrom = X_DEFAULT;
     if (xf86GetOptValBool(FlagOptions, FLAG_AIGLX, &value)) {
 	xf86Info.aiglx = value;
