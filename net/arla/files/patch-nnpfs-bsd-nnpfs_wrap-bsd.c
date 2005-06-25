--- nnpfs/bsd/nnpfs_wrap-bsd.c.orig	Sat Jun 25 13:30:29 2005
+++ nnpfs/bsd/nnpfs_wrap-bsd.c	Sat Jun 25 13:32:31 2005
@@ -38,6 +38,7 @@
 #include <nnpfs/nnpfs_syscalls.h>
 #include <nnpfs/nnpfs_deb.h>
 #include <nnpfs/nnpfs_wrap.h>
+#include <sys/param.h>
 
 RCSID("$Id: nnpfs_wrap-bsd.c,v 1.52 2005/03/30 07:14:18 lha Exp $");
 
@@ -52,8 +53,12 @@
 int
 nnpfs_is_nnpfs_dev (nnpfs_dev_t dev)
 {
+#if __FreeBSD_version > 600006
+    return nnpfs_minor(dev) >= 0 && nnpfs_minor(dev) < NNNPFS;
+#else
     return nnpfs_major (dev) == nnpfs_dev_major
 	&& nnpfs_minor(dev) >= 0 && nnpfs_minor(dev) < NNNPFS;
+#endif
 }
 
 static int
@@ -166,7 +171,9 @@
 	ret = nnpfs_install ();
 	if (ret == 0) {
 	    make_devices (&nnpfs_cdev);
+#if __FreeBSD_version < 600007
 	    nnpfs_dev_major = nnpfs_cdev.d_maj;
+#endif
 	    printf ("nnpfs: cdev: %d, syscall: %d\n",
 		    nnpfs_dev_major, nnpfs_syscall_num);
 	}
