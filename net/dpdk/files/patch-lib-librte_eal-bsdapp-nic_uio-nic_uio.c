--- lib/librte_eal/bsdapp/nic_uio/nic_uio.c.orig	2015-01-09 11:56:48.000000000 -0500
+++ lib/librte_eal/bsdapp/nic_uio/nic_uio.c	2015-01-09 11:57:05.000000000 -0500
@@ -175,13 +175,13 @@
 
 
 int
-nic_uio_open(struct cdev *dev, int oflags, int devtype, d_thread_t *td)
+nic_uio_open(struct cdev *dev, int oflags, int devtype, struct thread *td)
 {
 	return 0;
 }
 
 int
-nic_uio_close(struct cdev *dev, int fflag, int devtype, d_thread_t *td)
+nic_uio_close(struct cdev *dev, int fflag, int devtype, struct thread *td)
 {
 	return 0;
 }
