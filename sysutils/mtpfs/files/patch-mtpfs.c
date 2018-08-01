--- mtpfs.c.orig	2012-02-27 00:59:39 UTC
+++ mtpfs.c
@@ -1270,7 +1270,7 @@ mtpfs_rename (const char *oldname, const
 }
 
 static int
-mtpfs_statfs (const char *path, struct statfs *stbuf)
+mtpfs_statfs (const char *path, struct statvfs *stbuf)
 {
     DBG("mtpfs_statfs");
     stbuf->f_bsize=1024;
@@ -1282,7 +1282,7 @@ mtpfs_statfs (const char *path, struct s
 }
 
 void *
-mtpfs_init ()
+mtpfs_init (struct fuse_conn_info *conn)
 {
     LIBMTP_devicestorage_t *storage;
     DBG("mtpfs_init");
@@ -1298,8 +1298,14 @@ mtpfs_blank()
     // Do nothing
 }
 
+int
+mtpfs_blank_chmod(const char *path, mode_t mode)
+{
+	return (0);
+}
+
 static struct fuse_operations mtpfs_oper = {
-    .chmod   = mtpfs_blank,
+    .chmod   = mtpfs_blank_chmod,
     .release = mtpfs_release,
     .readdir = mtpfs_readdir,
     .getattr = mtpfs_getattr,
@@ -1428,7 +1434,7 @@ main (int argc, char *argv[])
 
     DBG("Start fuse");
 
-    fuse_stat=fuse_main (argc, argv, &mtpfs_oper);
+    fuse_stat=fuse_main (argc, argv, &mtpfs_oper, NULL);
     DBG("fuse_main returned %d\n", fuse_stat);
     return fuse_stat;
 }
