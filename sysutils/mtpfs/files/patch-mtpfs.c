--- mtpfs.c.orig	2008-08-05 07:29:29.000000000 +0200
+++ mtpfs.c	2012-10-30 00:47:13.487478272 +0100
@@ -534,7 +534,7 @@
         }
     }
     close (fi->fh);
-    return_unlock();
+    return_unlock(0);
 }
 
 void
@@ -1143,7 +1143,7 @@
 }
 
 static int
-mtpfs_statfs (const char *path, struct statfs *stbuf)
+mtpfs_statfs (const char *path, struct statvfs *stbuf)
 {
     DBG("mtpfs_statfs");
     stbuf->f_bsize=1024;
