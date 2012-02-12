--- libbrasero-media/scsi-cam.c.orig	2012-02-11 21:16:20.000000000 -0500
+++ libbrasero-media/scsi-cam.c	2012-02-11 21:17:13.000000000 -0500
@@ -103,6 +103,10 @@ brasero_scsi_command_issue_sync (gpointe
 	else if (cmd->info->direction & BRASERO_SCSI_WRITE)
 		direction = CAM_DIR_OUT;
 
+	if (size == 0)
+		direction = CAM_DIR_NONE;
+	direction |= CAM_DEV_QFRZDIS;
+
 	g_assert (direction > -1);
 
 	cam_fill_csio(&cam_ccb.csio,
