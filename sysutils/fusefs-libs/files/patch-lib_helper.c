--- lib/helper.c.orig	Mon Aug 15 16:03:59 2005
+++ lib/helper.c	Sun Oct  9 22:05:09 2005
@@ -22,7 +22,11 @@
 {
     if (progname)
         fprintf(stderr,
+#ifdef __FreeBSD__
+                "usage: %s [FUSE options]\n\n", progname);
+#else
                 "usage: %s mountpoint [FUSE options]\n\n", progname);
+#endif
 
     fprintf(stderr,
             "FUSE options:\n"
@@ -45,11 +49,19 @@
             "    debug                  enable debug output\n"
             "    fsname=NAME            set filesystem name in mtab\n"
             "    use_ino                let filesystem set inode numbers\n"
+#ifndef __FreeBSD__
             "    readdir_ino            try to fill in d_ino in readdir\n"
+#endif
             "    nonempty               allow mounts over non-empty file/dir\n"
             "    umask=M                set file permissions (octal)\n"
             "    uid=N                  set file owner\n"
             "    gid=N                  set file group\n"
+#ifdef __FreeBSD__
+            "\n"
+            "(Note that the above description regards to Linux. Hence these\n"
+            "options might work differently or might not work at all.\n"
+            "For more information, see mount_fusefs(8).)\n"
+#endif
             );
 }
 
@@ -275,11 +287,13 @@
         }
     }
 
+#ifndef __FreeBSD__
     if (*mountpoint == NULL) {
         fprintf(stderr, "missing mountpoint\n");
         fprintf(stderr, "see `%s -h' for usage\n", argv[0]);
         goto err;
     }
+#endif
     return 0;
 
  err:
@@ -377,8 +391,13 @@
         fuse_instance = NULL;
 
     fuse_destroy(fuse);
+#ifndef __FreeBSD__
     close(fd);
     fuse_unmount(mountpoint);
+#else
+    fuse_unmount(mountpoint);
+    close(fd);
+#endif
     free(mountpoint);
 }
 
