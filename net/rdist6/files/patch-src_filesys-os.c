--- src/filesys-os.c.dist	Fri Feb 16 03:01:04 1996
+++ src/filesys-os.c	Wed Feb  3 23:38:46 1999
@@ -180,4 +180,5 @@
 		mntstruct.me_flags |= MEFLAG_READONLY;
 #endif
+#ifdef MOUNT_NFS
 	switch ((ulong)((struct statfs*)mnt)->f_type) {
 	      case MOUNT_NFS:
@@ -191,4 +192,14 @@
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
