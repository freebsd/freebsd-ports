#
# fix --backup-dir
#  <http://lists.samba.org/archive/rsync/2004-May/009395.html>
#
--- backup.c	13 Mar 2004 20:18:03 -0000	1.28
+++ backup.c	4 May 2004 03:06:52 -0000
@@ -169,8 +169,9 @@ static int keep_backup(char *fname)
 	/* Check to see if this is a device file, or link */
 	if (IS_DEVICE(file->mode)) {
 		if (am_root && preserve_devices) {
-			make_bak_dir(backup_dir_buf);
-			if (do_mknod(backup_dir_buf, file->mode, file->u.rdev) != 0) {
+			if (do_mknod(backup_dir_buf, file->mode, file->u.rdev) < 0
+			    && (errno != ENOENT || make_bak_dir(backup_dir_buf) < 0
+			     || do_mknod(backup_dir_buf, file->mode, file->u.rdev) < 0)) {
 				rprintf(FERROR, "mknod %s failed: %s\n",
 					full_fname(backup_dir_buf), strerror(errno));
 			} else if (verbose > 2) {
@@ -186,10 +187,14 @@ static int keep_backup(char *fname)
 
 	if (!kept && S_ISDIR(file->mode)) {
 		/* make an empty directory */
-		make_bak_dir(backup_dir_buf);
-		do_mkdir(backup_dir_buf, file->mode);
-		ret_code = do_rmdir(fname);
+		if (do_mkdir(backup_dir_buf, file->mode) < 0
+		    && (errno != ENOENT || make_bak_dir(backup_dir_buf) < 0
+		     || do_mkdir(backup_dir_buf, file->mode) < 0)) {
+			rprintf(FINFO, "mkdir %s failed: %s\n",
+				full_fname(backup_dir_buf), strerror(errno));
+		}
 
+		ret_code = do_rmdir(fname);
 		if (verbose > 2) {
 			rprintf(FINFO, "make_backup: RMDIR %s returns %i\n",
 				full_fname(fname), ret_code);
@@ -207,8 +212,9 @@ static int keep_backup(char *fname)
 			}
 			kept = 1;
 		}
-		make_bak_dir(backup_dir_buf);
-		if (do_symlink(file->u.link, backup_dir_buf) != 0) {
+		if (do_symlink(file->u.link, backup_dir_buf) < 0
+		    && (errno != ENOENT || make_bak_dir(backup_dir_buf) < 0
+		     || do_symlink(file->u.link, backup_dir_buf) < 0)) {
 			rprintf(FERROR, "link %s -> %s : %s\n",
 				full_fname(backup_dir_buf), file->u.link, strerror(errno));
 		}
