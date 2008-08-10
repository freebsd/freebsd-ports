--- agent/mibgroup/ucd-snmp/disk.c.orig	2008-07-05 22:11:22.366362753 +0900
+++ agent/mibgroup/ucd-snmp/disk.c	2008-07-06 00:32:19.611196878 +0900
@@ -73,6 +73,9 @@
 #if HAVE_SYS_VFS_H
 #include <sys/vfs.h>
 #endif
+#if defined(__FreeBSD__) && __FreeBSD_version >= 700055
+#include <sys/ucred.h>
+#endif
 #if defined(HAVE_STATFS)
 #if HAVE_SYS_MOUNT_H
 #include <sys/mount.h>
@@ -491,6 +494,18 @@
     dummy = 1;
   }
   endfsent();			/* close /etc/fstab */
+#if defined(__FreeBSD__) && __FreeBSD_version >= 700055
+  {
+    struct statfs *mntbuf;
+    size_t i, mntsize;
+    mntsize = getmntinfo(&mntbuf, MNT_NOWAIT);
+    for (i = 0; i < mntsize; i++) {
+      if (strncmp(mntbuf[i].f_fstypename, "zfs", 3) == 0) {
+	add_device(mntbuf[i].f_mntonname, mntbuf[i].f_mntfromname, -1, minpercent, 0);
+      }
+    }
+  }
+#endif
   if(dummy != 0) {
     /*
      * dummy clause for else below
