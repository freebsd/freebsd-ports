--- fh.c.orig	2022-11-17 12:27:07 UTC
+++ fh.c
@@ -86,7 +86,7 @@ uint32 get_gen(backend_statstruct obuf, U(int fd), U(c
     backend_setegid(0);
     backend_seteuid(0);
 
-    if (fd != FD_NONE) {
+    if (fd != -1) {
 	res = ioctl(fd, EXT2_IOC_GETVERSION, &gen);
 	if (res == -1)
 	    gen = 0;
@@ -220,7 +220,7 @@ unfs3_fh_t fh_comp_raw(const char *path, struct svc_re
 
     fh.dev = buf.st_dev;
     fh.ino = buf.st_ino;
-    fh.gen = backend_get_gen(buf, FD_NONE, path);
+    fh.gen = backend_get_gen(buf, -1, path);
 
     /* special case for root directory */
     if (strcmp(path, "/") == 0)
@@ -341,7 +341,7 @@ post_op_fh3 fh_extend_type(nfs_fh3 fh, const char *pat
     st_cache = buf;
 
     return fh_extend_post(fh, buf.st_dev, buf.st_ino,
-			  backend_get_gen(buf, FD_NONE, path));
+			  backend_get_gen(buf, -1, path));
 }
 
 /*
