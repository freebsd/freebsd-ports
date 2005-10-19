--- lib/fuse.c.orig	Mon Oct  3 17:02:37 2005
+++ lib/fuse.c	Sun Oct  9 22:05:09 2005
@@ -1414,7 +1414,12 @@
 
 static int default_statfs(struct statfs *buf)
 {
+#ifdef __FreeBSD__
+    buf->f_namemax = 255;
+#else
     buf->f_namelen = 255;
+#endif
+
     buf->f_bsize = 512;
     return 0;
 }
@@ -1428,7 +1433,11 @@
     stbuf->f_bavail  = compatbuf->blocks_free;
     stbuf->f_files   = compatbuf->files;
     stbuf->f_ffree   = compatbuf->files_free;
+#ifdef __FreeBSD__
+    stbuf->f_namemax = compatbuf->namelen;
+#else
     stbuf->f_namelen = compatbuf->namelen;
+#endif
 }
 
 static void fuse_statfs(fuse_req_t req)
@@ -1761,8 +1770,10 @@
                 f->flags |= FUSE_HARD_REMOVE;
             else if (strcmp(opt, "use_ino") == 0)
                 f->flags |= FUSE_USE_INO;
+#ifndef FreeBSD
             else if (strcmp(opt, "readdir_ino") == 0)
                 f->flags |= FUSE_READDIR_INO;
+#endif
             else if (strcmp(opt, "direct_io") == 0)
                 f->flags |= FUSE_DIRECT_IO;
             else if (strcmp(opt, "kernel_cache") == 0)
@@ -1787,6 +1798,13 @@
         else
             free(xopts);
     }
+#ifdef __FreeBSD__
+    /*
+     * In FreeBSD, we always use these settings as inode numbers are needed to
+     * make getcwd(3) work.
+     */
+    f->flags |= FUSE_READDIR_INO;
+#endif
     return 0;
 }
 
