--- lib/ext2fs/ismounted.c.orig	Mon Feb 25 05:03:59 2002
+++ lib/ext2fs/ismounted.c	Sun Aug  4 02:51:39 2002
@@ -146,50 +146,6 @@
 	return retval;
 }
 
-/*
- * Check to see if we're dealing with the swap device.
- */
-static int is_swap_device(const char *file)
-{
-	FILE		*f;
-	char		buf[1024], *cp;
-	dev_t		file_dev;
-	struct stat	st_buf;
-	int		ret = 0;
-
-	file_dev = 0;
-#ifndef __GNU__ /* The GNU hurd is broken with respect to stat devices */
-	if (stat(file, &st_buf) == 0)
-		file_dev = st_buf.st_rdev;
-#endif	
-
-	if (!(f = fopen("/proc/swaps", "r")))
-		return 0;
-	/* Skip the first line */
-	fgets(buf, sizeof(buf), f);
-	while (!feof(f)) {
-		if (!fgets(buf, sizeof(buf), f))
-			break;
-		if ((cp = strchr(buf, ' ')) != NULL)
-			*cp = 0;
-		if ((cp = strchr(buf, '\t')) != NULL)
-			*cp = 0;
-		if (strcmp(buf, file) == 0) {
-			ret++;
-			break;
-		}
-#ifndef __GNU__
-		if (file_dev && (stat(buf, &st_buf) == 0) &&
-		    file_dev == st_buf.st_rdev) {
-			ret++;
-			break;
-		}
-#endif
-	}
-	fclose(f);
-	return ret;
-}
-
 static errcode_t check_mntent(const char *file, int *mount_flags,
 			      char *mtpt, int mtlen)
 {
@@ -248,6 +204,50 @@
 	return 0;
 }
 #endif /* HAVE_GETMNTINFO */
+
+/*
+ * Check to see if we're dealing with the swap device.
+ */
+static int is_swap_device(const char *file)
+{
+	FILE		*f;
+	char		buf[1024], *cp;
+	dev_t		file_dev;
+	struct stat	st_buf;
+	int		ret = 0;
+
+	file_dev = 0;
+#ifndef __GNU__ /* The GNU hurd is broken with respect to stat devices */
+	if (stat(file, &st_buf) == 0)
+		file_dev = st_buf.st_rdev;
+#endif	
+
+	if (!(f = fopen("/proc/swaps", "r")))
+		return 0;
+	/* Skip the first line */
+	fgets(buf, sizeof(buf), f);
+	while (!feof(f)) {
+		if (!fgets(buf, sizeof(buf), f))
+			break;
+		if ((cp = strchr(buf, ' ')) != NULL)
+			*cp = 0;
+		if ((cp = strchr(buf, '\t')) != NULL)
+			*cp = 0;
+		if (strcmp(buf, file) == 0) {
+			ret++;
+			break;
+		}
+#ifndef __GNU__
+		if (file_dev && (stat(buf, &st_buf) == 0) &&
+		    file_dev == st_buf.st_rdev) {
+			ret++;
+			break;
+		}
+#endif
+	}
+	fclose(f);
+	return ret;
+}
 
 /*
  * ext2fs_check_mount_point() returns 1 if the device is mounted, 0
