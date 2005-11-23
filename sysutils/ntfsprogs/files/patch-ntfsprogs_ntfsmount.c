--- ntfsprogs/ntfsmount.c.orig	Wed Nov 23 12:33:56 2005
+++ ntfsprogs/ntfsmount.c	Wed Nov 23 12:32:15 2005
@@ -228,7 +228,11 @@
 		size = 0;
 	sfs->f_ffree = size;
 	/* Maximum length of filenames. */
+#ifdef __FreeBSD__
+	sfs->f_namemax = NTFS_MAX_NAME_LEN;
+#else
 	sfs->f_namelen = NTFS_MAX_NAME_LEN;
+#endif
 	return 0;
 }
 
