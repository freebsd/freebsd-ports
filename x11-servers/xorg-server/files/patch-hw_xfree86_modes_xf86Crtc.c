--- hw/xfree86/modes/xf86Crtc.c.orig	2014-04-15 01:01:57 UTC
+++ hw/xfree86/modes/xf86Crtc.c
@@ -1774,6 +1774,9 @@ SetCompatOutput(xf86CrtcConfigPtr config
     DisplayModePtr maxmode = NULL, testmode, mode;
     int o, compat = -1, count, mincount = 0;
 
+    if (config->num_output == 0)
+        return NULL;
+
     /* Look for one that's definitely connected */
     for (o = 0; o < config->num_output; o++) {
         test = config->output[o];
