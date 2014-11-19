--- conf/nfs_prot/nfs_prot_freebsd3.h.orig	2014-10-28 17:12:59 UTC
+++ conf/nfs_prot/nfs_prot_freebsd3.h
@@ -85,9 +85,11 @@ struct ufs_extattr_per_mount;
 #define na_ctime	ctime
 #define na_fileid	fileid
 #define na_fsid		fsid
+#define na_gid		gid
 #define na_mode		mode
 #define na_mtime	mtime
 #define na_nlink	nlink
+#define na_rdev		rdev
 #define na_size		size
 #define na_type		type
 #define na_uid		uid
