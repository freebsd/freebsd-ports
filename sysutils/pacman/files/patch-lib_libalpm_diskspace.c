--- lib/libalpm/diskspace.c.orig	2020-12-03 11:37:30 UTC
+++ lib/libalpm/diskspace.c
@@ -71,7 +71,7 @@ static void mount_point_list_free(alpm_list_t *mount_p
 
 static int mount_point_load_fsinfo(alpm_handle_t *handle, alpm_mountpoint_t *mountpoint)
 {
-#if defined(HAVE_GETMNTENT)
+#if HAVE_GETMNTENT
 	/* grab the filesystem usage */
 	if(statvfs(mountpoint->mount_dir, &(mountpoint->fsp)) != 0) {
 		_alpm_log(handle, ALPM_LOG_WARNING,
