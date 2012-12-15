--- mtpfs.c	2012-02-26 16:59:39.000000000 -0800
+++ mtpfs.c	2012-12-12 19:11:46.955525173 -0800
@@ -1270,7 +1270,7 @@
 }
 
 static int
-mtpfs_statfs (const char *path, struct statfs *stbuf)
+mtpfs_statfs (const char *path, struct statvfs *stbuf)
 {
     DBG("mtpfs_statfs");
     stbuf->f_bsize=1024;
@@ -1282,7 +1282,7 @@
 }
 
 void *
-mtpfs_init ()
+mtpfs_init (struct fuse_conn_info *conn)
 {
     LIBMTP_devicestorage_t *storage;
     DBG("mtpfs_init");
@@ -1298,8 +1298,14 @@
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
@@ -1428,7 +1434,7 @@
 
     DBG("Start fuse");
 
-    fuse_stat=fuse_main (argc, argv, &mtpfs_oper);
+    fuse_stat=fuse_main (argc, argv, &mtpfs_oper, NULL);
     DBG("fuse_main returned %d\n", fuse_stat);
     return fuse_stat;
 }
