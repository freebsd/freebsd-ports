--- src/nautilus-burn-drive-monitor.c.orig        2007-07-10 15:06:23.000000000 -0400
+++ src/nautilus-burn-drive-monitor.c        2008-01-05 13:51:44.000000000 -0500
@@ -618,7 +618,8 @@ nautilus_burn_drive_monitor_get_drive_fo
                  */
                 if (drive->priv->device != NULL &&
                    (strcmp (drive->priv->device, target) == 0 ||
-                    strcmp (drive->priv->device, device) == 0)) {
+                    strcmp (drive->priv->device, device) == 0 ||
+                    strcmp (drive->priv->cdrecord_device, device) == 0)) {
                         ret = nautilus_burn_drive_ref (drive);
                         break;
                 }
@@ -683,6 +684,8 @@ hal_drive_from_udi (LibHalContext *ctx,
         NautilusBurnDrive        *drive;
         char                    **write_speeds = NULL;
         char                     *raw_device = NULL;
+        char                     *cam_path = NULL;
+        char                     *cam_device = NULL;
 
         LIBHAL_CHECK_LIBHALCONTEXT (ctx, FALSE);
 
@@ -711,6 +714,8 @@ hal_drive_from_udi (LibHalContext *ctx,
 
                 LIBHAL_PROP_EXTRACT_STRING  ("block.device",               drive->priv->device);
                 LIBHAL_PROP_EXTRACT_STRING  ("block.solaris.raw_device",   raw_device);
+                LIBHAL_PROP_EXTRACT_STRING  ("block.freebsd.atapi_cam_device", cam_device);
+                LIBHAL_PROP_EXTRACT_STRING  ("block.freebsd.cam_path",     cam_path);
                 LIBHAL_PROP_EXTRACT_STRING  ("storage.model",              drive->priv->display_name);
 
                 LIBHAL_PROP_EXTRACT_INT ("storage.cdrom.read_speed",   drive->priv->max_speed_read);
@@ -736,6 +741,17 @@ hal_drive_from_udi (LibHalContext *ctx,
                 drive->priv->device = raw_device;
         }
 
+        if (cam_device != NULL) {
+                g_free (drive->priv->device);
+                drive->priv->device = cam_device;
+        }
+
+        if (cam_path != NULL) {
+                drive->priv->cdrecord_device = cam_path;
+        } else {
+                drive->priv->cdrecord_device = g_strdup (drive->priv->device);
+        }
+
         drive->priv->drive_udi = g_strdup (udi);
         drive->priv->write_speeds = hal_parse_write_speeds (write_speeds);
         /* we do not own write_speeds so do not free it. */
