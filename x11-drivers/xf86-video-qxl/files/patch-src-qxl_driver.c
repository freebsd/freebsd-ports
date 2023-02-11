--- src/qxl_driver.c.orig	2016-12-19 17:25:56 UTC
+++ src/qxl_driver.c
@@ -807,8 +807,8 @@ qxl_screen_init (SCREEN_INIT_ARGS_DECL)
     
     CHECK_POINT ();
     
-    pScreen->width = pScrn->currentMode->HDisplay;
-    pScreen->height = pScrn->currentMode->VDisplay;
+    pScreen->width = qxl->primary_mode.x_res;
+    pScreen->height = qxl->primary_mode.y_res;
     
     if (!xf86CrtcScreenInit (pScreen))
 	return FALSE;
@@ -1005,6 +1005,11 @@ qxl_pre_init_common(ScrnInfoPtr pScrn)
         get_bool_option (qxl->options, OPTION_DEBUG_RENDER_FALLBACKS, "QXL_DEBUG_RENDER_FALLBACKS");
     qxl->num_heads =
         get_int_option (qxl->options, OPTION_NUM_HEADS, "QXL_NUM_HEADS");
+    if (qxl->num_heads == 0) {
+        xf86DrvMsg (scrnIndex, X_INFO, "QXL_NUM_HEADS not configured, "
+            "defaulting to 1\n");
+        qxl->num_heads = 1;
+    }
 
     qxl->deferred_fps = get_int_option(qxl->options, OPTION_SPICE_DEFERRED_FPS, "XSPICE_DEFERRED_FPS");
     if (qxl->deferred_fps > 0)
