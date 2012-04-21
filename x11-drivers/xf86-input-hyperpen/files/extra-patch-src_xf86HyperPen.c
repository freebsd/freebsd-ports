--- src/xf86HyperPen.c.orig	2009-02-26 16:31:24.000000000 -0600
+++ src/xf86HyperPen.c	2010-05-03 12:29:11.000000000 -0500
@@ -719,6 +719,9 @@
 {
     LocalDevicePtr	local = (LocalDevicePtr)pHyp->public.devicePrivate;
     HyperPenDevicePtr	priv = (HyperPenDevicePtr)PRIVATE(pHyp);
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 7
+    Atom axis_labels[3] = { 0 };
+#endif
 
     if (xf86HypOpen(local) != Success) {
 	if (local->fd >= 0) {
@@ -730,6 +733,9 @@
 /* Set the real values */
     InitValuatorAxisStruct(pHyp,
 			   0,
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 7
+			   axis_labels[0],
+#endif
 			   0, /* min val */
 			   priv->hypXSize, /* max val */
 			   LPI2CPM(priv->hypRes), /* resolution */
@@ -737,6 +743,9 @@
 			   LPI2CPM(priv->hypRes)); /* max_res */
     InitValuatorAxisStruct(pHyp,
 			   1,
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 7
+			   axis_labels[1],
+#endif
 			   0, /* min val */
 			   priv->hypYSize, /* max val */
 			   LPI2CPM(priv->hypRes), /* resolution */
@@ -744,6 +753,9 @@
 			   LPI2CPM(priv->hypRes)); /* max_res */
     InitValuatorAxisStruct(pHyp,
 			   2,
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 7
+			   axis_labels[2],
+#endif
 			   0, /* min val */
 			   511, /* max val */
 			   512, /* resolution */
@@ -765,8 +777,10 @@
     int			loop;
     LocalDevicePtr	local = (LocalDevicePtr)pHyp->public.devicePrivate;
     HyperPenDevicePtr	priv = (HyperPenDevicePtr)PRIVATE(pHyp);
-
-
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 7
+    Atom btn_labels[4] = { 0 };
+    Atom axis_labels[3] = { 0 };
+#endif
 
     switch (what) {
 	case DEVICE_INIT:
@@ -779,6 +793,9 @@
 
 	    if (InitButtonClassDeviceStruct(pHyp,
 					    nbbuttons,
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 7
+					    btn_labels,
+#endif
 					    map) == FALSE) {
 		ErrorF("unable to allocate Button class device\n");
 		return !Success;
@@ -802,6 +819,9 @@
 
 	    if (InitValuatorClassDeviceStruct(pHyp,
 		   nbaxes,
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 7
+		   axis_labels,
+#endif
 #if GET_ABI_MAJOR(ABI_XINPUT_VERSION) < 3
 		   xf86GetMotionEvents,
 #endif
