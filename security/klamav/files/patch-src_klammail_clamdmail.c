--- src/klammail/clamdmail.c.orig	2008-09-16 08:46:48.000000000 -0300
+++ src/klammail/clamdmail.c	2008-09-16 08:47:25.000000000 -0300
@@ -160,7 +160,7 @@
                 if(fsync(fd) == -1) {
 //                         cli_dbgmsg("fsync() failed for descriptor %d\n", fd);
                         close(fd);
-                        return CL_EFSYNC;
+                        return CL_EIO;
                 }
 
                 close(fd);
