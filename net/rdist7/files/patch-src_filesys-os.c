--- src/filesys-os.c.orig	2001-10-22 13:29:22.000000000 -0700
+++ src/filesys-os.c	2024-03-19 19:48:24.454801000 -0700
@@ -144,6 +144,7 @@
 		mntstruct.me_flags |= MEFLAG_READONLY;
 
 	mntstruct.me_path = vmt2dataptr(mnt, VMT_STUB);
+#ifdef MNT_NFS
 	switch ((ulong)(struct vmount*)mnt->vmt_gfstype) {
 	      case MNT_NFS:
 		mntstruct.me_type = METYPE_NFS;
@@ -152,6 +153,16 @@
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
 
 	mnt = (struct vmount*)((mnt->vmt_length)+(ulong)mnt);
 	entries_left--;
@@ -244,6 +255,7 @@
 	    }
 	}
 #endif /* FMT_TYPE == FMT_STATFS_STR */
+#ifdef MOUNT_NFS
 #if	FMT_TYPE == FMT_STATFS_STR && !defined(HAVE_GETVFSBYNAME)
 	if (strcmp(mnt->f_fstypename, MOUNT_NFS) == 0) {
 		(void) snprintf(remote_dev, sizeof(remote_dev), "%s",
@@ -270,6 +282,7 @@
 		break;
 	}
 #endif	/* FMT_TYPE == FMT_STATFS_STR */
+#endif
 
 	mnt = (struct statfs*)(sizeof(struct statfs)+(ulong)mnt);
 	entries_left--;
