--- cmds.c.orig	Mon Jul 22 00:28:19 2002
+++ cmds.c	Fri Sep  3 16:35:01 2004
@@ -17,6 +17,18 @@
 #include <utime.h>
 #include <errno.h>
 
+#if __FreeBSD__
+#include <ufs/ufs/ufsmount.h>
+#include <isofs/cd9660/cd9660_mount.h>
+#if __FreeBSD_version >= 500019
+#include <fs/msdosfs/msdosfsmount.h>
+#include <fs/ntfs/ntfsmount.h>
+#else
+#include <msdosfs/msdosfsmount.h>
+#include <ntfs/ntfsmount.h>
+#endif
+#endif
+
 #if	HAVE_LINUX_MOUNT
 #include <linux/fs.h>
 #endif
@@ -564,6 +576,10 @@
 				flags |= MNT_RDONLY;
 				break;
 
+			case 'u':
+				flags |= MNT_UPDATE;
+				break;
+
 			case 's':
 				flags |= MNT_NOSUID;
 				break;
@@ -594,35 +610,47 @@
 #elif	HAVE_BSD_MOUNT
 	{
 		struct	    ufs_args ufs;
-		struct	    adosfs_args adosfs;
 		struct	    iso_args iso;
-		struct	    mfs_args mfs;
 		struct	    msdosfs_args msdosfs;
+		struct	    ntfs_args ntfs;
 		void *	    args;
 
 		if(!strcmp(type, "ffs") || !strcmp(type, "ufs")) {
+			memset(&ufs, 0, sizeof(ufs));
 			ufs.fspec = (char*) argv[0];
 			args = &ufs;
-		} else if(!strcmp(type, "adosfs")) {
-			adosfs.fspec = (char*) argv[0];
-			adosfs.uid = 0;
-			adosfs.gid = 0;
-			args = &adosfs;
 		} else if(!strcmp(type, "cd9660")) {
+			memset(&iso, 0, sizeof(iso));
 			iso.fspec = (char*) argv[0];
 			args = &iso;
-		} else if(!strcmp(type, "mfs")) {
-			mfs.fspec = (char*) argv[0];
-			args = &mfs;
+		} else if(!strcmp(type, "ext2fs")) {
+			memset(&ufs, 0, sizeof(ufs));
+			ufs.fspec = (char*) argv[0];
+			args = &ufs;
 		} else if(!strcmp(type, "msdos")) {
+			memset(&msdosfs, 0, sizeof(msdosfs));
 			msdosfs.fspec = (char*) argv[0];
-			msdosfs.uid = 0;
-			msdosfs.gid = 0;
+			if (flags & MNT_RDONLY) {
+				msdosfs.export.ex_flags = MNT_EXRDONLY;
+				msdosfs.mask = msdosfs.dirmask = 0555;
+			} else {
+				msdosfs.mask = msdosfs.dirmask = 7555;
+			}
 			args = &msdosfs;
+		} else if(!strcmp(type, "ntfs")) {
+			memset(&ntfs, 0, sizeof(ntfs));
+			ntfs.fspec = (char*) argv[0];
+			if (flags & MNT_RDONLY) {
+				ntfs.export.ex_flags = MNT_EXRDONLY;
+				ntfs.mode = 0555;
+			} else {
+				ntfs.mode = 0755;
+			}
+			args = &ntfs;
 		} else {
 			fprintf(stderr, "Unknown filesystem type: %s", type);
 			fprintf(stderr,
-			    "Supported: ffs ufs adosfs cd9660 mfs msdos\n");
+			    "Supported: ffs ufs cd9660 ext2fs msdos ntfs\n");
 			return;
 		}
 
