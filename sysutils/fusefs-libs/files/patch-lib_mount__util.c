--- lib/mount_util.c.orig	2015-05-22 09:24:02 UTC
+++ lib/mount_util.c
@@ -344,20 +344,3 @@ int fuse_mnt_check_empty(const char *pro
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
