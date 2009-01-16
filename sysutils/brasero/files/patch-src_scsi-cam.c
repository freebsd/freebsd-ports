--- src/scsi-cam.c.orig	2009-01-13 21:35:42.000000000 -0500
+++ src/scsi-cam.c	2009-01-13 21:36:01.000000000 -0500
@@ -62,7 +62,7 @@ typedef struct _BraseroScsiCmd BraseroSc
 #define BRASERO_SCSI_CMD_OPCODE_OFF			0
 #define BRASERO_SCSI_CMD_SET_OPCODE(command)		(command->cmd [BRASERO_SCSI_CMD_OPCODE_OFF] = command->info->opcode)
 
-#define OPEN_FLAGS			O_RDWR /*|O_EXCL */|O_NONBLOCK
+#define OPEN_FLAGS			O_RDONLY /*|O_EXCL */|O_NONBLOCK
 
 BraseroScsiResult
 brasero_scsi_command_issue_sync (gpointer command,
@@ -158,8 +158,8 @@ brasero_device_handle_open (const gchar 
 
 	g_assert (path != NULL);
 
-	if (exclusive)
-		flags |= O_EXCL;
+/*	if (exclusive)
+		flags |= O_EXCL;*/
 
 	/* cam_open_device() fails unless we use O_RDWR */
 	cam = cam_open_device (path, O_RDWR);
