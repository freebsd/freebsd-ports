--- cd-drive.c.orig	Mon Sep  8 15:24:07 2003
+++ cd-drive.c	Sun Dec 21 02:40:36 2003
@@ -693,28 +693,133 @@
 #endif /* __linux__ */
 
 #ifdef __FreeBSD__
+static void
+get_cd_properties (char *id, int *max_rd_speed, int *max_wr_speed,
+	CDDriveType *type)
+{
+    	int i;
+	const char *argv[20];
+	char *dev_str, *stdout_data, *rd_speed, *wr_speed, *drive_cap;
+
+	*max_rd_speed = -1;
+	*max_wr_speed = -1;
+	*type = 0;
+
+	i = 0;
+	argv[i++] = "cdrecord";
+	argv[i++] = "-prcap";
+	dev_str = g_strdup_printf ("dev=%s", id);
+	argv[i++] = dev_str;
+	argv[i++] = NULL;
+
+	if (g_spawn_sync (NULL,
+			  (char **)argv,
+			  NULL,
+			  G_SPAWN_SEARCH_PATH | G_SPAWN_STDERR_TO_DEV_NULL,
+			  NULL, NULL,
+			  &stdout_data,
+			  NULL,
+			  NULL,
+			  NULL)) {
+		rd_speed = strstr (stdout_data, "Maximum read  speed:");
+		if (rd_speed != NULL) {
+		    	char *tok;
+			rd_speed += strlen ("Maximum read  speed:");
+			for (tok = strtok (rd_speed, " (),\t\n"); 
+				tok && strcmp (tok, "CD"); 
+				tok = strtok (NULL, " (),\t\n")) {}
+			tok = strtok (NULL, " (),\t\n"); /* Get the CD speed. */
+			*max_rd_speed = atol (tok);
+		}
+		else {
+		    	rd_speed = strstr (stdout_data, "Maximum read  speed in kB/s:");
+			if (rd_speed != NULL) {
+			    	char *tok;
+			    	rd_speed += strlen ("Maximum read  speed in kB/s:");
+				for (tok = strtok (rd_speed, " (),\t\n");
+					tok && strcmp (tok, "CD");
+					tok = strtok (NULL, " (),\t\n")) {}
+				tok = strtok (NULL, " (),\t\n"); /* Get the CD speed. */
+				*max_rd_speed = atol (tok);
+			}
+		}
+
+		wr_speed = strstr (stdout_data, "Maximum write speed:");
+		if (wr_speed != NULL) {
+		    	char *tok;
+		    	wr_speed += strlen ("Maximum write speed:");
+			for (tok = strtok (wr_speed, " (),\t\n");
+				tok && strcmp (tok, "CD");
+				tok = strtok (NULL, " (),\t\n")) {}
+			tok = strtok (NULL, " (),\t\n"); /* Get the CD speed. */
+			*max_wr_speed = atol (tok);
+		}
+		else {
+		    	wr_speed = strstr (stdout_data, "Maximum write speed in kB/s:");
+			if (wr_speed != NULL) {
+			    	char *tok;
+			    	wr_speed += strlen ("Maximum write speed in kB/s:");
+				for (tok = strtok (wr_speed, " (),\t\n");
+					tok && strcmp (tok, "CD");
+					tok = strtok (NULL, " (),\t\n")) {}
+				tok = strtok (NULL, " (),\t\n"); /* Get the CD speed. */
+				*max_wr_speed = atol (tok);
+			}
+		}
+		drive_cap = strstr (stdout_data, "Does write DVD-RAM media");
+		if (drive_cap != NULL) {
+		    	*type |= CDDRIVE_TYPE_DVD_RAM_RECORDER;
+		}
+		drive_cap = strstr (stdout_data, "Does read DVD-R media");
+		if (drive_cap != NULL) {
+		    	*type |= CDDRIVE_TYPE_DVD_RW_RECORDER;
+		}
+		drive_cap = strstr (stdout_data, "Does read DVD-ROM media");
+		if (drive_cap != NULL) {
+		    	*type |= CDDRIVE_TYPE_DVD_DRIVE;
+		}
+		drive_cap = strstr (stdout_data, "Does write CD-RW media");
+		if (drive_cap != NULL) {
+		    	*type |= CDDRIVE_TYPE_CDRW_RECORDER;
+		}
+		drive_cap = strstr (stdout_data, "Does write CD-R media");
+		if (drive_cap != NULL) {
+		    	*type |= CDDRIVE_TYPE_CD_RECORDER;
+		}
+		drive_cap = strstr (stdout_data, "Does read CD-R media");
+		if (drive_cap != NULL) {
+		    	*type |= CDDRIVE_TYPE_CD_DRIVE;
+		}
+		g_free (stdout_data);
+	}
+
+	g_free (dev_str);
+}
+
 static GList *
 freebsd_scan (gboolean recorder_only)
 {
 	GList *cdroms_list = NULL;
 	const char *dev_type = "cd";
-	int fd;
 	int speed = 16; /* XXX Hardcode the write speed for now. */
-	int max_speed = CDR_MAX_SPEED;
 	int i = 0;
+	int cnode = 1; /* Use the CD device's 'c' node. */
 
 	while (1) {
-		CDDriveType type;
 		CDDrive *cdrom;
-		gchar *cam_path, *dev;
+		gchar *cam_path;
 		struct cam_device *cam_dev;
 
-		type = 0;
 		cam_path = g_strdup_printf ("/dev/%s%dc", dev_type, i);
 
 		if (!g_file_test (cam_path, G_FILE_TEST_EXISTS)) {
 			g_free (cam_path);
-			break;
+			cam_path = g_strdup_printf ("/dev/%s%d", dev_type, i);
+			cnode = 0;
+			if (!g_file_test (cam_path, G_FILE_TEST_EXISTS)) {
+				g_free (cam_path);
+				break;
+			}
 		}
 
 		if ((cam_dev = cam_open_spec_device (dev_type, i, O_RDWR, NULL)) == NULL) {
@@ -723,47 +828,41 @@
 			continue;
 		}
 
-		/* XXX Other controllers might need to be added. */
-		if ((strncmp (cam_dev->sim_name, "ata", 3)) == 0) {
-			dev = g_strdup_printf ("/dev/a%s%dc", dev_type, i);
-		} else {
-			dev = g_strdup (cam_path);
-		}
-
-		g_free (cam_path);
-
-		if ((fd = open (dev, O_RDWR, 0)) < 0) {
-			g_free (dev);
-			free (cam_dev);
-			i++;
-			continue;
-		}
-
-		type |= CDDRIVE_TYPE_CD_DRIVE;
-		if (ioctl (fd, CDRIOCWRITESPEED, &max_speed) >= 0) {
-			/* XXX is it CD-R or CD-RW ? */
-			type |= CDDRIVE_TYPE_CD_RECORDER;
-		}
-
-		close (fd);
-
-		if (type & CDDRIVE_TYPE_CD_RECORDER
-				|| type & CDDRIVE_TYPE_CDRW_RECORDER
-				|| recorder_only == FALSE) {
-			cdrom = g_new0 (CDDrive, 1);
-			cdrom->display_name = g_strdup_printf ("%s %s", cam_dev->inq_data.vendor, cam_dev->inq_data.revision);
-			cdrom->device = g_strdup (dev);
-			cdrom->max_speed_read = speed;
-			cdrom->max_speed_write = speed;
-			cdrom->cdrecord_id = g_strdup_printf ("%d,%d,%d", cam_dev->path_id, cam_dev->target_id, cam_dev->target_lun);
-			cdrom->type = type;
-
-			add_dvd_plus (cdrom);
+		cdrom = g_new0 (CDDrive, 1);
+		cdrom->display_name = g_strdup_printf ("%s %s", cam_dev->inq_data.vendor, cam_dev->inq_data.revision);
+		cdrom->device = g_strdup (cam_path);
+		cdrom->cdrecord_id = g_strdup_printf ("%d,%d,%d", cam_dev->path_id, cam_dev->target_id, cam_dev->target_lun);
+		/* Attempt to get more specific information from
+		 * this drive by using cdrecord.
+		 */
+		get_cd_properties (cdrom->cdrecord_id,
+			&(cdrom->max_speed_read),
+			&(cdrom->max_speed_write),
+			&(cdrom->type));
+		if (cdrom->type & CDDRIVE_TYPE_CD_RECORDER
+				|| cdrom->type & CDDRIVE_TYPE_CDRW_RECORDER
+				|| cdrom->type & CDDRIVE_TYPE_DVD_RAM_RECORDER
+				|| cdrom->type & CDDRIVE_TYPE_DVD_RW_RECORDER
+				|| !recorder_only) {
+
+			if (cdrom->max_speed_read == -1) {
+		    		cdrom->max_speed_read = speed;
+			}
+			if (cdrom->max_speed_write == -1) {
+			    	cdrom->max_speed_write = speed;
+			}
+
+			if (cdrom->type & CDDRIVE_TYPE_DVD_DRIVE) {
+				add_dvd_plus (cdrom);
+			}
 
 			cdroms_list = g_list_append (cdroms_list, cdrom);
 		}
+		else {
+		    	cd_drive_free (cdrom);
+		}
 
-		g_free (dev);
+		g_free (cam_path);
 		free (cam_dev);
 
 		i++;
