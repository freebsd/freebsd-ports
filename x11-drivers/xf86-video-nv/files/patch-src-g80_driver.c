--- src/g80_driver.c.orig	2008-08-04 17:08:54.000000000 -0500
+++ src/g80_driver.c	2009-02-28 20:24:36.000000000 -0600
@@ -206,11 +206,8 @@
     CARD32 tmp;
     memType BAR1sizeKB;
 
-    if(flags & PROBE_DETECT) {
-        xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-                "G80 PROBE_DETECT unimplemented\n");
-        return FALSE;
-    }
+    if(flags & PROBE_DETECT)
+        return TRUE;
 
     /* Check the number of entities, and fail if it isn't one. */
     if(pScrn->numEntities != 1)
