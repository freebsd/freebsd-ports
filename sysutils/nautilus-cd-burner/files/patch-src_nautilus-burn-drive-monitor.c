--- src/nautilus-burn-drive-monitor.c.orig	Thu Nov  2 12:56:50 2006
+++ src/nautilus-burn-drive-monitor.c	Thu Nov  2 12:56:21 2006
@@ -683,6 +683,7 @@ hal_drive_from_udi (LibHalContext *ctx,
 	NautilusBurnDrive        *drive;
 	char                    **write_speeds = NULL;
 	char                     *raw_device = NULL;
+	char                     *cam_path = NULL;
 
 	LIBHAL_CHECK_LIBHALCONTEXT (ctx, FALSE);
 
@@ -711,6 +712,7 @@ hal_drive_from_udi (LibHalContext *ctx,
 
 		LIBHAL_PROP_EXTRACT_STRING  ("block.device",               drive->priv->device);
 		LIBHAL_PROP_EXTRACT_STRING  ("block.solaris.raw_device",   raw_device);
+		LIBHAL_PROP_EXTRACT_STRING  ("block.freebsd.cam_path",     cam_path);
 		LIBHAL_PROP_EXTRACT_STRING  ("storage.model",              drive->priv->display_name);
 
 		LIBHAL_PROP_EXTRACT_INT ("storage.cdrom.read_speed",   drive->priv->max_speed_read);
@@ -734,6 +736,11 @@ hal_drive_from_udi (LibHalContext *ctx,
 	if (raw_device != NULL) {
 		g_free (drive->priv->device);
 		drive->priv->device = raw_device;
+	}
+
+	if (cam_path != NULL) {
+		g_free (drive->priv->device);
+		drive->priv->device = cam_path;
 	}
 
 	drive->priv->drive_udi = g_strdup (udi);
