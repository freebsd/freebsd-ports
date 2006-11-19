--- src/nautilus-burn-drive-monitor.c.orig	Fri Sep 29 14:18:23 2006
+++ src/nautilus-burn-drive-monitor.c	Sun Nov 19 13:28:16 2006
@@ -683,6 +683,8 @@ hal_drive_from_udi (LibHalContext *ctx,
 	NautilusBurnDrive        *drive;
 	char                    **write_speeds = NULL;
 	char                     *raw_device = NULL;
+	char                     *cam_path = NULL;
+	char                     *cam_device = NULL;
 
 	LIBHAL_CHECK_LIBHALCONTEXT (ctx, FALSE);
 
@@ -711,6 +713,8 @@ hal_drive_from_udi (LibHalContext *ctx,
 
 		LIBHAL_PROP_EXTRACT_STRING  ("block.device",               drive->priv->device);
 		LIBHAL_PROP_EXTRACT_STRING  ("block.solaris.raw_device",   raw_device);
+		LIBHAL_PROP_EXTRACT_STRING ("block.freebsd.atapi_cam_device", cam_device);
+		LIBHAL_PROP_EXTRACT_STRING  ("block.freebsd.cam_path",     cam_path);
 		LIBHAL_PROP_EXTRACT_STRING  ("storage.model",              drive->priv->display_name);
 
 		LIBHAL_PROP_EXTRACT_INT ("storage.cdrom.read_speed",   drive->priv->max_speed_read);
@@ -734,6 +738,17 @@ hal_drive_from_udi (LibHalContext *ctx,
 	if (raw_device != NULL) {
 		g_free (drive->priv->device);
 		drive->priv->device = raw_device;
+	}
+
+	if (cam_device != NULL) {
+		g_free (drive->priv->device);
+		drive->priv->device = cam_device;
+	}
+
+	if (cam_path != NULL) {
+		drive->priv->cdrecord_device = cam_path;
+	} else {
+		drive->priv->cdrecord_device = g_strdup (drive->priv->device);
 	}
 
 	drive->priv->drive_udi = g_strdup (udi);
