--- nautilus-burn-drive.c.orig	Wed Mar 22 11:08:38 2006
+++ nautilus-burn-drive.c	Thu Jul 13 22:15:30 2006
@@ -687,7 +687,6 @@
 	struct cd_toc_entry              entry;
 	int                              i;
 #endif
-	int                              type;
 #ifndef CDROM_DATA_TRACK
 #define CDROM_DATA_TRACK 4
 #endif
@@ -699,6 +698,10 @@
 
 	if (ioctl (fd, CDIOREADTOCHEADER, &header) < 0) {
 		close (fd);
+		if (errno == EINVAL)
+			/* If you try to read the TOC header of a blank disc
+			 * on FreeBSD, you get EINVAL. */
+			return CDS_NO_INFO;
 	    	return -1;
 	}
 
@@ -862,7 +865,7 @@
 		*is_blank = mmc_profile & 0x10000;
 
 	disc_type = get_disc_type (device);
-	disc_type_get_info (disc_type, is_blank, has_data, has_audio);
+	disc_type_get_info (disc_type, NULL, has_data, has_audio);
 
 	switch (mmc_profile & 0xFFFF) {
 	case -1:
@@ -1767,7 +1770,11 @@
 #ifdef USE_GNOME_MOUNT
 	cmd = g_strdup_printf ("gnome-mount --eject --no-ui --device=%s", drive->device);
 #else
+#ifdef __FreeBSD__
+	cmd = g_strdup_printf ("cdcontrol -f %s eject", drive->device);
+#else
 	cmd = g_strdup_printf ("eject %s", drive->device);
+#endif
 #endif
 
 	res = g_spawn_command_line_sync (cmd, NULL, NULL, NULL, NULL);
