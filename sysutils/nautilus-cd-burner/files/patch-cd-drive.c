--- cd-drive.c.orig	Mon Sep  8 15:24:07 2003
+++ cd-drive.c	Thu Oct  2 13:09:02 2003
@@ -702,6 +702,7 @@
 	int speed = 16; /* XXX Hardcode the write speed for now. */
 	int max_speed = CDR_MAX_SPEED;
 	int i = 0;
+	int cnode = 1; /* Use the CD device's 'c' node. */
 
 	while (1) {
 		CDDriveType type;
@@ -714,7 +715,12 @@
 
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
@@ -725,7 +731,11 @@
 
 		/* XXX Other controllers might need to be added. */
 		if ((strncmp (cam_dev->sim_name, "ata", 3)) == 0) {
-			dev = g_strdup_printf ("/dev/a%s%dc", dev_type, i);
+		    	if (cnode) {
+				dev = g_strdup_printf ("/dev/a%s%dc", dev_type, i);
+			} else {
+			    	dev = g_strdup_printf ("/dev/a%s%d", dev_type, i);
+			}
 		} else {
 			dev = g_strdup (cam_path);
 		}
@@ -742,7 +752,7 @@
 		type |= CDDRIVE_TYPE_CD_DRIVE;
 		if (ioctl (fd, CDRIOCWRITESPEED, &max_speed) >= 0) {
 			/* XXX is it CD-R or CD-RW ? */
-			type |= CDDRIVE_TYPE_CD_RECORDER;
+			type |= CDDRIVE_TYPE_CDRW_RECORDER;
 		}
 
 		close (fd);
