--- base/gdevvglb.c.orig	2007-09-25 13:31:24 UTC
+++ base/gdevvglb.c
@@ -149,10 +149,13 @@ vgalib_close(gx_device * dev)
 }
 
 static gx_color_index
-vgalib_map_rgb_color(gx_device * dev, gx_color_value red,
-		     gx_color_value green, gx_color_value blue)
+vgalib_map_rgb_color(gx_device * dev, const gx_color_value cv[])
 {
-    return pc_4bit_map_rgb_color(dev, red, green, blue);
+	gx_color_value r = cv[0];
+	gx_color_value g = cv[1];
+	gx_color_value b = cv[2];
+
+    return pc_4bit_map_rgb_color(dev, cv);
 }
 
 static int
@@ -368,12 +371,3 @@ vgalib_put_params(gx_device * dev, gs_pa
     }
     return 0;
 }
-
-#ifdef GS_DEVS_SHARED
-extern void gs_lib_register_device(const gx_device *dev);
-void
-gs_shared_init(void)
-{
-  gs_lib_register_device(&gs_vgalib_device);
-}
-#endif
