--- lib/mount_util.c.orig	2008-02-04 00:23:30.000000000 -0500
+++ lib/mount_util.c	2008-02-04 00:23:58.000000000 -0500
@@ -224,20 +224,3 @@
 	}
 	return 0;
 }
-
-int fuse_mnt_check_fuseblk(void)
-{
-	char buf[256];
-	FILE *f = fopen("/proc/filesystems", "r");
-	if (!f)
-		return 1;
-
-	while (fgets(buf, sizeof(buf), f))
-		if (strstr(buf, "fuseblk\n")) {
-			fclose(f);
-			return 1;
-		}
-
-	fclose(f);
-	return 0;
-}
