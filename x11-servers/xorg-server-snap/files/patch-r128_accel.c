Index: programs/Xserver/hw/xfree86/drivers/ati/r128_accel.c
===================================================================
RCS file: /cvs/xorg/xc/programs/Xserver/hw/xfree86/drivers/ati/r128_accel.c,v
retrieving revision 1.3
retrieving revision 1.3.4.1
diff -u -u -r1.3 -r1.3.4.1
--- programs/Xserver/hw/xfree86/drivers/ati/r128_accel.c	16 Jun 2004 09:43:58 -0000	1.3
+++ programs/Xserver/hw/xfree86/drivers/ati/r128_accel.c	15 Dec 2004 09:22:02 -0000	1.3.4.1
@@ -237,17 +237,23 @@
         i = 0;
         do {
             ret = drmCommandNone(info->drmFD, DRM_R128_CCE_IDLE);
-        } while ( ret && errno == EBUSY && i++ < R128_IDLE_RETRY );
+        } while ( ret && errno == EBUSY && i++ < (R128_IDLE_RETRY * R128_IDLE_RETRY) );
 
 	if (ret && ret != -EBUSY) {
 	    xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
 		       "%s: CCE idle %d\n", __FUNCTION__, ret);
 	}
 
+	if (i > R128_IDLE_RETRY) {
+	    xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+		       "%s: (DEBUG) CCE idle took i = %d\n", __FUNCTION__, i);
+	}
+
 	if (ret == 0) return;
 
 	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
 		   "Idle timed out, resetting engine...\n");
+	R128CCE_STOP(pScrn, info);
 	R128EngineReset(pScrn);
 
 	/* Always restart the engine when doing CCE 2D acceleration */
