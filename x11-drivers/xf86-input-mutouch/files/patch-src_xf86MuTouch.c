--- src/xf86MuTouch.c.orig	2010-05-03 13:16:26.000000000 -0500
+++ src/xf86MuTouch.c	2010-05-03 13:16:34.000000000 -0500
@@ -426,9 +426,9 @@
 	 * or we will feed X with quite bogus event positions.
 	 */
         if (priv->x_inverted)
-          cur_x = priv->max_x - cur_x;
+          cur_x = priv->max_x - cur_x + priv->min_x;
         if (priv->y_inverted)
-          cur_y = priv->max_y - cur_y;
+          cur_y = priv->max_y - cur_y + priv->min_y;
 	xf86PostMotionEvent(local_to_use->dev, TRUE, 0, 2, cur_x, cur_y);
 
 	/*
@@ -749,6 +749,10 @@
   unsigned char		req[MuT_PACKET_SIZE];
   unsigned char		reply[MuT_BUFFER_SIZE];
   char			*id_string = DEVICE_ID(local->private_flags) == FINGER_ID ? "finger" : "stylus";
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 7
+  Atom btn_label;
+  Atom axis_labels[2] = { 0, 0 };
+#endif
 
   switch(mode) {
 
@@ -766,7 +770,11 @@
       /*
        * Device reports button press for up to 1 button.
        */
-      if (InitButtonClassDeviceStruct(dev, 1, map) == FALSE) {
+      if (InitButtonClassDeviceStruct(dev, 1,
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 7
+				      &btn_label,
+#endif
+				      map) == FALSE) {
 	ErrorF("Unable to allocate ButtonClassDeviceStruct\n");
 	return !Success;
       }
@@ -779,6 +787,9 @@
        * screen to fit one meter.
        */
       if (InitValuatorClassDeviceStruct(dev, 2,
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 7
+				      axis_labels,
+#endif
 #if GET_ABI_MAJOR(ABI_XINPUT_VERSION) < 3
 					xf86GetMotionEvents,
 #endif
@@ -787,11 +798,19 @@
 	return !Success;
       }
       else {
-	InitValuatorAxisStruct(dev, 0, priv->min_x, priv->max_x,
+	InitValuatorAxisStruct(dev, 0,
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 7
+			       axis_labels[0],
+#endif
+			       priv->min_x, priv->max_x,
 			       9500,
 			       0     /* min_res */,
 			       9500  /* max_res */);
-	InitValuatorAxisStruct(dev, 1, priv->min_y, priv->max_y,
+	InitValuatorAxisStruct(dev, 1,
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 7
+			       axis_labels[1],
+#endif
+			       priv->min_y, priv->max_y,
 			       10500,
 			       0     /* min_res */,
 			       10500 /* max_res */);
