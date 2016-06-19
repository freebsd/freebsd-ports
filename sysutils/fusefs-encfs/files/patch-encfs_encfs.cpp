--- encfs/encfs.cpp.orig	2015-03-24 20:45:16 UTC
+++ encfs/encfs.cpp
@@ -529,6 +529,17 @@ int encfs_open(const char *path, struct 
   return res;
 }
 
+int encfs_create(const char *path, mode_t mode, struct fuse_file_info *file)
+{
+  int res;
+
+  res = encfs_mknod(path, mode, 0);
+  if (res)
+    return res;
+
+  return encfs_open(path, file);
+}
+
 int _do_flush(FileNode *fnode) {
   /* Flush can be called multiple times for an open file, so it doesn't
      close the file.  However it is important to call close() for some
