--- src/filesys-os.c.orig	1998-11-10 04:09:59 UTC
+++ src/filesys-os.c
@@ -187,6 +187,7 @@ mntent_t *getmountent(fptr)
 	if (mnt->f_flags & M_RDONLY)
 		mntstruct.me_flags |= MEFLAG_READONLY;
 #endif
+#ifdef MOUNT_NFS
 	switch ((ulong)((struct statfs*)mnt)->f_type) {
 	      case MOUNT_NFS:
 		(void) sprintf(remote_dev, "%s", mnt->f_mntfromname);
@@ -198,6 +199,16 @@ mntent_t *getmountent(fptr)
 		mntstruct.me_type = METYPE_OTHER;
 		break;
 	}
+#else
+	if ((((struct statfs*)mnt)->f_flags & MNT_LOCAL) == 0) {
+		(void) sprintf(remote_dev, "%s", mnt->f_mntfromname);
+		mntstruct.me_path = remote_dev;
+		mntstruct.me_type = METYPE_NFS;
+	} else {
+		mntstruct.me_path = mnt->f_mntonname;
+		mntstruct.me_type = METYPE_OTHER;
+	}
+#endif
 
 	mnt++;
 	entries_left--;
