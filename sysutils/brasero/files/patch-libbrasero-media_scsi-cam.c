--- libbrasero-media/scsi-cam.c.orig	2009-09-25 10:39:03.000000000 -0400
+++ libbrasero-media/scsi-cam.c	2009-10-10 13:30:06.000000000 -0400
@@ -184,6 +184,8 @@ brasero_device_handle_open (const gchar 
 		handle->fd = fd;
 	}
 	else {
+		int serrno;
+
 		if (code) {
 			if (errno == EAGAIN
 			||  errno == EWOULDBLOCK
@@ -193,6 +195,15 @@ brasero_device_handle_open (const gchar 
 				*code = BRASERO_SCSI_ERRNO;
 		}
 
+		serrno = errno;
+
+		if (fd > -1)
+			close (fd);
+		if (cam)
+			cam_close_device (cam);
+
+		errno = serrno;
+
 		return NULL;
 	}
 
