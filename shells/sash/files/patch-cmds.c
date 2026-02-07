--- cmds.c.orig	2014-03-07 13:06:29 UTC
+++ cmds.c
@@ -17,9 +17,20 @@
 #include <utime.h>
 #include <errno.h>
 
+#if __FreeBSD__
+#include <ufs/ufs/extattr.h>
+#include <ufs/ufs/quota.h>
+#include <ufs/ufs/ufsmount.h>
+#include <isofs/cd9660/cd9660_mount.h>
+#include <fs/msdosfs/msdosfsmount.h>
+#if __FreeBSD_version < 1000000
+#include <fs/ntfs/ntfsmount.h>
+#define HAVE_BSD_NTFSMOUNT
+#endif
+#endif
+
 #if	HAVE_LINUX_MOUNT
 #include <linux/fs.h>
-#endif
 
 /* Need to tell loop.h what the actual dev_t type is. */
 #undef dev_t
@@ -32,6 +43,7 @@
 #undef dev_t
 #define dev_t dev_t
 
+#endif
 
 int
 do_echo(int argc, const char ** argv)
@@ -716,6 +728,10 @@ do_mount(int argc, const char ** argv)
 				flags |= MNT_RDONLY;
 				break;
 
+			case 'u':
+				flags |= MNT_UPDATE;
+				break;
+
 			case 's':
 				flags |= MNT_NOSUID;
 				break;
@@ -748,46 +764,58 @@ do_mount(int argc, const char ** argv)
 #elif	HAVE_BSD_MOUNT
 	{
 		struct	    ufs_args ufs;
-		struct	    adosfs_args adosfs;
 		struct	    iso_args iso;
-		struct	    mfs_args mfs;
 		struct	    msdosfs_args msdosfs;
+#ifdef	HAVE_BSD_NTFSMOUNT
+		struct	    ntfs_args ntfs;
+#endif
 		void *	    args;
 
 		if (!strcmp(type, "ffs") || !strcmp(type, "ufs"))
 		{
+			memset(&ufs, 0, sizeof(ufs));
 			ufs.fspec = (char*) argv[0];
 			args = &ufs;
 		}
-		else if (!strcmp(type, "adosfs"))
-		{
-			adosfs.fspec = (char*) argv[0];
-			adosfs.uid = 0;
-			adosfs.gid = 0;
-			args = &adosfs;
-		}
 		else if (!strcmp(type, "cd9660"))
 		{
+			memset(&iso, 0, sizeof(iso));
 			iso.fspec = (char*) argv[0];
 			args = &iso;
 		}
-		else if (!strcmp(type, "mfs"))
-		{
-			mfs.fspec = (char*) argv[0];
-			args = &mfs;
-		}
 		else if (!strcmp(type, "msdos"))
 		{
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
+#ifdef	HAVE_BSD_NTFSMOUNT
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
+#endif
 		}
 		else
 		{
 			fprintf(stderr, "Unknown filesystem type: %s", type);
 			fprintf(stderr,
-			    "Supported: ffs ufs adosfs cd9660 mfs msdos\n");
+#ifdef	HAVE_BSD_NTFSMOUNT
+			    "Supported: ffs ufs cd9660 ext2fs msdos ntfs\n");
+#else
+			    "Supported: ffs ufs cd9660 ext2fs msdos\n");
+#endif
 
 			return 1;
 		}
@@ -1448,7 +1476,7 @@ do_where(int argc, const char ** argv)
 		 */
 		dirName = path;
 
-		if (dirName == '\0')
+		if (dirName == NULL)
 			dirName = ".";
 
 		/*
