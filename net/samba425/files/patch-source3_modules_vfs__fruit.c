--- source3/modules/vfs_fruit.c.orig	2026-06-30 19:00:05 UTC
+++ source3/modules/vfs_fruit.c
@@ -2339,36 +2339,53 @@ static ssize_t fruit_pread_meta_stream(vfs_handle_stru
 }
 
 static ssize_t fruit_pread_meta_stream(vfs_handle_struct *handle,
-				       files_struct *fsp, void *data,
-				       size_t n, off_t offset)
+                                       files_struct *fsp, void *data,
+                                       size_t n, off_t offset)
 {
-	struct fio *fio = fruit_get_complete_fio(handle, fsp);
-	ssize_t nread;
-	int ret;
+        struct fio *fio = fruit_get_complete_fio(handle, fsp);
+        ssize_t nread;
+        int ret;
+        char *p = (char *)data;
 
-	if ((fio == NULL) || fio->fake_fd) {
-		return -1;
-	}
+        if ((fio == NULL) || fio->fake_fd) {
+                return -1;
+        }
 
-	nread = SMB_VFS_NEXT_PREAD(handle, fsp, data, n, offset);
-	if (nread == -1 || ((size_t)nread == n)) {
-		return nread;
-	}
+        nread = SMB_VFS_NEXT_PREAD(handle, fsp, data, n, offset);
+        if (nread <= 0) {
+                /*
+                 * fruit_meta_open_stream() removes O_CREAT flag
+                 * from xattr open. This results in vfs_streams_xattr
+                 * not generating an FSP extension for the files_struct
+                 * and causes subsequent pread() of stream to return
+                 * nread=0 if pread() occurs before pwrite().
+                 */
+                return nread;
+        }
 
-	DBG_ERR("Removing [%s] after short read [%zd]\n",
-		fsp_str_dbg(fsp), nread);
+        if ((size_t)nread == n) {
+                if (offset == 0 && nread > 3 && p[0] == 0 && p[1] == 'F' && p[2] == 'P') {
+                        DBG_NOTICE("Fixing AFP_Info of [%s]\n",
+                                   fsp_str_dbg(fsp));
+                        p[0] = 'A';
+                }
+                return nread;
+        }
 
-	ret = SMB_VFS_NEXT_UNLINKAT(handle,
-			fsp->conn->cwd_fsp,
-			fsp->fsp_name,
-			0);
-	if (ret != 0) {
-		DBG_ERR("Removing [%s] failed\n", fsp_str_dbg(fsp));
-		return -1;
-	}
+        DBG_ERR("Removing [%s] after short read [%zd]\n",
+                fsp_str_dbg(fsp), nread);
 
-	errno = EINVAL;
-	return -1;
+        ret = SMB_VFS_NEXT_UNLINKAT(handle,
+                                   fsp->conn->cwd_fsp,
+                                   fsp->fsp_name,
+                                   0);
+        if (ret != 0) {
+                DBG_ERR("Removing [%s] failed\n", fsp_str_dbg(fsp));
+                return -1;
+        }
+
+        errno = EINVAL;
+        return -1;
 }
 
 static ssize_t fruit_pread_meta_adouble(vfs_handle_struct *handle,
