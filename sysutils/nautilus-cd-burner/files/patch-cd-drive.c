--- cd-drive.c.orig	Wed Sep 22 09:20:04 2004
+++ cd-drive.c	Mon Oct  4 02:20:47 2004
@@ -270,9 +270,21 @@
 {
 	int fd;
 	int mmc_profile;
+#ifdef __FreeBSD__
+	struct cam_device *cam;
+#endif
 
 	g_return_val_if_fail (device != NULL, CD_MEDIA_TYPE_ERROR);
 
+#ifdef __FreeBSD__
+	cam = cam_open_device (device, O_RDWR);
+	if (cam == NULL) {
+		return CD_MEDIA_TYPE_ERROR;
+	}
+
+	fd = cam->fd;
+#else
+
 	fd = open (device, O_RDWR|O_EXCL|O_NONBLOCK);
 	if (fd < 0) {
 		if (errno == EBUSY) {
@@ -280,6 +292,7 @@
 		}
 		return CD_MEDIA_TYPE_ERROR;
 	}
+#endif
 
 	mmc_profile = get_mmc_profile (fd);
 
@@ -307,7 +320,11 @@
 		}
 	}
 
+#ifdef __FreeBSD__
+	cam_close_device (cam);
+#else
 	close (fd);
+#endif
 
 	switch (mmc_profile) {
 	case -1:
@@ -442,10 +459,21 @@
 	int secs;
 	int mmc_profile;
 	gint64 size;
+#ifdef __FreeBSD__
+	struct cam_device *cam;
+#endif
 
 	g_return_val_if_fail (device != NULL, CD_MEDIA_SIZE_UNKNOWN);
 
 	secs = 0;
+#ifdef __FreeBSD__
+	cam = cam_open_device (device, O_RDWR);
+	if (cam == NULL) {
+		return CD_MEDIA_SIZE_UNKNOWN;
+	}
+
+	fd = cam->fd;
+#else
 
 	fd = open (device, O_RDWR|O_EXCL|O_NONBLOCK);
 	if (fd < 0) {
@@ -454,6 +482,7 @@
 		}
 		return CD_MEDIA_SIZE_UNKNOWN;
 	}
+#endif
 
 	mmc_profile = get_mmc_profile (fd);
 
@@ -476,7 +505,11 @@
 		size = CD_MEDIA_SIZE_NA;
 	}
 
+#ifdef __FreeBSD__
+	cam_close_device (cam);
+#else
 	close (fd);
+#endif
 
 	return size;
 }
@@ -595,9 +628,81 @@
 #endif /* USE_HAL */
 
 #if defined(__linux__) || defined(__FreeBSD__)
+static int
+get_device_max_write_speed (char *device)
+{
+	int fd;
+	int max_speed;
+	int read_speed, write_speed;
+#ifdef __FreeBSD__
+	struct cam_device *cam;
+#endif
+
+	max_speed = -1;
+#ifdef __FreeBSD__
+	cam = cam_open_device (device, O_RDWR);
+	if (cam == NULL) {
+		return -1;
+	}
+
+	fd = cam->fd;
+#else
+
+	fd = open (device, O_RDWR|O_EXCL|O_NONBLOCK);
+	if (fd < 0) {
+		return -1;
+	}
+#endif
 
+	get_read_write_speed (fd, &read_speed, &write_speed);
+#ifdef __FreeBSD__
+	cam_close_device (cam);
+#else
+	close (fd);
+#endif
+	max_speed = (int)floor  (write_speed) / CD_ROM_SPEED;
 
+	return max_speed;
+}
 
+#if !defined(__linux)
+static int
+get_device_max_read_speed (char *device)
+{
+	int fd;
+	int max_speed;
+	int read_speed, write_speed;
+#ifdef __FreeBSD__
+	struct cam_device *cam;
+#endif
+
+	max_speed = -1;
+#ifdef __FreeBSD__
+	cam = cam_open_device (device, O_RDWR);
+	if (cam == NULL) {
+		return -1;
+	}
+
+	fd = cam->fd;
+#else
+
+	fd = open (device, O_RDWR|O_EXCL|O_NONBLOCK);
+	if (fd < 0) {
+		return -1;
+	}
+#endif
+
+	get_read_write_speed (fd, &read_speed, &write_speed);
+#ifdef __FreeBSD__
+	cam_close_device (cam);
+#else
+	close (fd);
+#endif
+	max_speed = (int)floor  (read_speed) / CD_ROM_SPEED;
+
+	return max_speed;
+}
+#endif
 #endif /* __linux__ || __FreeBSD__ */
 
 #if defined (__linux__)
@@ -800,49 +905,7 @@
 	return NULL;
 }
 
-#if !defined(__linux)
-static int
-get_device_max_read_speed (char *device)
-{
-	int fd;
-	int max_speed;
-	int read_speed, write_speed;
 
-	max_speed = -1;
-
-	fd = open (device, O_RDWR|O_EXCL|O_NONBLOCK);
-	if (fd < 0) {
-		return -1;
-	}
-
-	get_read_write_speed (fd, &read_speed, &write_speed);
-	close (fd);
-	max_speed = (int)floor  (read_speed) / CD_ROM_SPEED;
-
-	return max_speed;
-}
-#endif
-
-static int
-get_device_max_write_speed (char *device)
-{
-	int fd;
-	int max_speed;
-	int read_speed, write_speed;
-
-	max_speed = -1;
-
-	fd = open (device, O_RDWR|O_EXCL|O_NONBLOCK);
-	if (fd < 0) {
-		return -1;
-	}
-
-	get_read_write_speed (fd, &read_speed, &write_speed);
-	close (fd);
-	max_speed = (int)floor  (write_speed) / CD_ROM_SPEED;
-
-	return max_speed;
-}
 
 static char *
 get_scsi_cd_name (int bus, int id, int lun, const char *dev,
