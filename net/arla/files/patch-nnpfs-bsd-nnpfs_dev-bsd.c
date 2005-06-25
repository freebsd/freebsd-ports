--- nnpfs/bsd/nnpfs_dev-bsd.c.orig	Sat Jun 25 15:14:30 2005
+++ nnpfs/bsd/nnpfs_dev-bsd.c	Sat Jun 25 15:13:42 2005
@@ -43,8 +43,13 @@
 int
 nnpfs_devopen(nnpfs_dev_t dev, int flag, int devtype, d_thread_t *proc)
 {
+#if __FreeBSD_version < 600007
     NNPFSDEB(XDEBDEV, ("nnpfsopen dev = %d.%d, flag = %d, devtype = %d\n", 
 		     major(dev), minor(dev), flag, devtype));
+#else
+    NNPFSDEB(XDEBDEV, ("nnpfsopen dev = %d, flag = %d, devtype = %d\n",
+                      minor(dev), flag, devtype));
+#endif
     return nnpfs_devopen_common(dev);
 }
 
@@ -72,10 +77,17 @@
 	     int flags,
 	     d_thread_t *p)
 {
+#if __FreeBSD_version < 600007
     NNPFSDEB(XDEBDEV, ("nnpfs_devioctl dev = %d.%d, cmd = %lu, "
 		     "data = %lx, flags = %x\n", 
 		     major(dev), minor(dev), (unsigned long)cmd,
 		     (unsigned long)data, flags));
+#else
+    NNPFSDEB(XDEBDEV, ("nnpfs_devioctl dev = %d, cmd = %lu, "
+                     "data = %lx, flags = %x\n",
+                     minor(dev), (unsigned long)cmd,
+                     (unsigned long)data, flags));
+#endif
     return ENOTTY;
 }
 
@@ -257,7 +269,9 @@
 #ifdef HAVE_STRUCT_CDEVSW_D_SPARE
     d_spare: NULL,
 #endif
+#if __FreeBSD_version < 600007
     d_maj: 128,			/* XXX */
+#endif
 #ifdef HAVE_STRUCT_CDEVSW_D_DUMP
     d_dump: nodump,
 #endif
@@ -346,8 +360,10 @@
 	if (chan->status & CHANNEL_OPENED) {
 #if defined(__DragonFly__)
             nnpfs_devclose(make_adhoc_dev(&nnpfs_cdev, i), 0, 0, NULL);
-#elif defined(__FreeBSD__) && __FreeBSD_version >= 502103
+#elif defined(__FreeBSD__) && __FreeBSD_version >= 502103 && __FreeBSD_version < 600007
 	    nnpfs_devclose(findcdev(makedev(0, i)), 0, 0, NULL);
+#elif defined(__FreeBSD__) && __FreeBSD_version > 600006
+            nnpfs_devclose(nnpfs_dev[i].dev, 0, 0, NULL);
 #else
 	    nnpfs_devclose(makedev(0, i), 0, 0, NULL);
 #endif
