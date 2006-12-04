--- sshfs.c.orig	Fri Aug 18 10:38:37 2006 +0000
+++ sshfs.c	Fri Sep 29 14:22:54 2006 +0000
@@ -147,6 +147,7 @@ struct sshfs_file {
     int is_seq;
     int connver;
     int modifver;
+    int refs;
 };
 
 struct sshfs {
@@ -1768,6 +1769,7 @@ static int sshfs_open_common(const char 
     pthread_cond_init(&sf->write_finished, NULL);
     /* Assume random read after open */
     sf->is_seq = 0;
+    sf->refs = 1;
     sf->next_pos = 0;
     sf->modifver= sshfs.modifver;
     sf->connver = sshfs.connver;
@@ -1851,6 +1853,19 @@ static int sshfs_fsync(const char *path,
     return sshfs_flush(path, fi);
 }
 
+static void sshfs_file_put(struct sshfs_file *sf)
+{
+    sf->refs--;
+    if (!sf->refs)
+        g_free(sf);
+}
+
+static struct sshfs_file *sshfs_file_get(struct sshfs_file *sf)
+{
+    sf->refs++;
+    return sf;
+}
+
 static int sshfs_release(const char *path, struct fuse_file_info *fi)
 {
     struct sshfs_file *sf = get_sshfs_file(fi);
@@ -1861,7 +1876,7 @@ static int sshfs_release(const char *pat
     }
     buf_free(handle);
     chunk_put_locked(sf->readahead);
-    g_free(sf);
+    sshfs_file_put(sf);
     return 0;
 }
 
@@ -2084,6 +2099,7 @@ static void sshfs_write_end(struct reque
     }
     list_del(&req->list);
     pthread_cond_broadcast(&sf->write_finished);
+    sshfs_file_put(sf);
 }
 
 static int sshfs_write(const char *path, const char *wbuf, size_t size,
@@ -2110,7 +2126,7 @@ static int sshfs_write(const char *path,
     iov[1].iov_len = size;
     if (!sshfs.sync_write && !sf->write_error)
         err = sftp_request_send(SSH_FXP_WRITE, iov, 2, sshfs_write_begin,
-                                 sshfs_write_end, 0, sf, NULL);
+                                 sshfs_write_end, 0, sshfs_file_get(sf), NULL);
     else
         err = sftp_request_iov(SSH_FXP_WRITE, iov, 2, SSH_FXP_STATUS, NULL);
     buf_free(&buf);