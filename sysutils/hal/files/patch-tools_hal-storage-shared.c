--- tools/hal-storage-shared.c.orig	2008-05-07 19:24:24.000000000 -0400
+++ tools/hal-storage-shared.c	2008-10-20 14:53:35.000000000 -0400
@@ -297,6 +297,9 @@ handle_unmount (LibHalContext *hal_ctx, 
 	char *mount_point_to_unmount;
 	gboolean mounted_by_other_uid;
 	FILE *hal_mtab_new;
+#ifdef __FreeBSD__
+	char *rdevice = NULL;
+#endif
 
 #ifdef DEBUG
 	printf ("device                           = %s\n", device);
@@ -473,7 +476,20 @@ line_found:
 #endif
 	if (option_force)
 		args[na++] = "-f";
-	args[na++] = (char *) device;
+#ifdef __FreeBSD__
+	dbus_error_init (&error);
+	if (libhal_device_property_exists (hal_ctx, udi, "volume.freebsd.real_mounted_device", NULL)) {
+		rdevice = libhal_device_get_property_string (hal_ctx, udi, "volume.freebsd.real_mounted_device", &error);
+		if (dbus_error_is_set (&error)) {
+			dbus_error_free (&error);
+			unknown_error ("Error while getting volume.freebsd.real_mounted_device");
+		}
+	}
+	if (rdevice)
+		args[na++] = rdevice;
+	else
+#endif
+		args[na++] = (char *) device;
 	args[na++] = NULL;
 
 #ifdef DEBUG
@@ -497,6 +513,10 @@ line_found:
 		unknown_error ("Cannot spawn " UMOUNT);
 	}
 
+#ifdef __FreeBSD__
+	g_free (rdevice);
+#endif
+
 	/* check if unmount was succesful */
 	if (exit_status != 0) {
 		printf ("%s error %d, stdout='%s', stderr='%s'\n", UMOUNT, exit_status, sout, serr);
