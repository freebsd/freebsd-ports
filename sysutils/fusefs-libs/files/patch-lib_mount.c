--- lib/mount.c.orig	Sun Oct  2 11:16:12 2005
+++ lib/mount.c	Sun Oct  9 22:05:09 2005
@@ -21,7 +21,7 @@
 #define FUSERMOUNT_PROG         "fusermount"
 #define FUSE_COMMFD_ENV         "_FUSE_COMMFD"
 
-
+#ifndef __FreeBSD__
 /* return value:
  * >= 0  => fd
  * -1    => error
@@ -66,9 +66,11 @@
     }
     return *(int*)CMSG_DATA(cmsg);
 }
+#endif
 
 void fuse_unmount(const char *mountpoint)
 {
+#ifndef __FreeBSD__
     const char *mountprog = FUSERMOUNT_PROG;
     char umount_cmd[1024];
 
@@ -77,10 +79,53 @@
 
     umount_cmd[sizeof(umount_cmd) - 1] = '\0';
     system(umount_cmd);
+#else
+    /*
+     * This is how we could do unmount-by-the-daemon in FreeBSD.
+     * Alas, by the time we get here, fuse_kern_chan_destroy
+     * has closed up the device, so this will fail.
+     * Maybe fuse_kern_chan_destroy should be castrated for FreeBSD?
+     * Well, let's stay on the safe side for now.
+     */
+#if 0
+    /*
+     * We keep on not wanting to rely on the mountpoint argument
+     * so let's just look up our device as in mount_fusefs(8)...
+     * we don't trust the environment here though.
+     */
+    char dev[128];
+    char *ssc, *umount_cmd;
+    FILE *sf;
+    int rv;
+    char *seekscript =
+    "/usr/bin/fstat  /dev/fuse* |\n"
+    "/usr/bin/awk '{if ($3 == %d) print $10}' |\n"
+    "/usr/bin/sort |\n"
+    "/usr/bin/uniq |\n"
+    "/usr/bin/awk '{ i+=1; if(i > 1){ exit (1); }; printf; }; END{if (i==0) exit (1)}'";
+
+    asprintf(&ssc, seekscript, getpid());
+
+    errno = 0; 	
+    sf = popen(ssc, "r");
+    if (! sf)
+        return;
+
+    fgets(dev, sizeof(dev), sf);
+    rv = pclose(sf);
+    if (rv)
+        return;
+
+    asprintf(&umount_cmd, "/sbin/umount %s", dev); 
+    system(umount_cmd);
+#endif
+    (void)mountpoint;
+#endif
 }
 
 int fuse_mount(const char *mountpoint, const char *opts)
 {
+#ifndef __FreeBSD__
     const char *mountprog = FUSERMOUNT_PROG;
     int fds[2], pid;
     int res;
@@ -133,6 +178,40 @@
     waitpid(pid, NULL, 0); /* bury zombie */
 
     return rv;
+#else
+    int fd;
+    char *dev;
+
+    (void)mountpoint;
+    (void)opts;
+
+    dev = getenv("FUSE_DEV_FD");
+
+    if (dev) {
+        errno = 0;
+        fd = strtol(dev, NULL, 10);
+    
+        if (errno) {
+            perror("bad value given in FUSE_DEV_FD");
+            return -1;
+        }
+    
+        if (fd < 0)
+            return -1;
+    
+        return fd;
+    }
+
+    dev = getenv("FUSE_DEV_NAME");
+
+    if (! dev)
+	dev = "/dev/fuse";
+
+    if ((fd = open(dev, O_RDWR)) < 0)
+        perror("failed to open fuse device");
+
+    return fd;
+#endif
 }
 
 int fuse_mount_compat1(const char *mountpoint, const char *args[])
