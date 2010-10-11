--- src/lowntfs-3g.c.orig	2010-10-02 08:22:46.000000000 -0300
+++ src/lowntfs-3g.c	2010-10-10 22:04:14.000000000 -0300
@@ -2541,10 +2541,14 @@
 	if (ntfs_inode_close(ni))
 		set_fuse_error(&ret);
 done :
+#ifndef __FreeBSD__
 	if (ret < 0)
 		fuse_reply_err(req, -ret);
 	else
 		fuse_reply_bmap(req, lidx);
+#else
+	;
+#endif
 }
 
 #ifdef HAVE_SETXATTR
