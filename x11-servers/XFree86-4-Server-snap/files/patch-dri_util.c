Index: lib/GL/dri/dri_util.c
===================================================================
RCS file: /home/ncvs/xfree/xc/lib/GL/dri/dri_util.c,v
retrieving revision 1.6
retrieving revision 1.7
diff -u -u -r1.6 -r1.7
--- lib/GL/dri/dri_util.c	15 Feb 2003 22:12:29 -0000	1.6
+++ lib/GL/dri/dri_util.c	28 Apr 2003 17:01:25 -0000	1.7
@@ -921,7 +921,7 @@
     int directCapable;
     __DRIscreenPrivate *psp;
     drmHandle hFB, hSAREA;
-    char *BusID, *driverName;
+    char *BusID, *driverName = NULL;
     drmMagic magic;
 
     if (!XF86DRIQueryDirectRenderingCapable(dpy, scrn, &directCapable)) {
@@ -1010,6 +1010,8 @@
 	(void)XF86DRICloseConnection(dpy, scrn);
 	return NULL;
     }
+    if (driverName)
+	Xfree(driverName);
 
     /* install driver's callback functions */
     memcpy(&psp->DriverAPI, driverAPI, sizeof(struct __DriverAPIRec));
