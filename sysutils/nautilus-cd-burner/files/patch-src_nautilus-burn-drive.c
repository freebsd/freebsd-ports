--- src/nautilus-burn-drive.c.orig	Thu Jul 13 22:51:49 2006
+++ src/nautilus-burn-drive.c	Thu Jul 13 22:52:25 2006
@@ -806,7 +806,11 @@ nautilus_burn_drive_eject (NautilusBurnD
 #ifdef USE_GNOME_MOUNT
 	cmd = g_strdup_printf ("gnome-mount --eject --no-ui --device=%s", drive->priv->device);
 #else
+#ifdef __FreeBSD_
+	cmd = g_strdup_printf ("cdcontrol -f %s eject", drive->priv->device);
+#else
 	cmd = g_strdup_printf ("eject %s", drive->priv->device);
+#endif
 #endif
 
 	res = g_spawn_command_line_sync (cmd, NULL, NULL, NULL, NULL);
