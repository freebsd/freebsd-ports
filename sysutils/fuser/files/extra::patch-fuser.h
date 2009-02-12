--- fuser.h.orig	2009-02-13 02:34:32.000000000 +0300
+++ fuser.h	2009-02-13 02:34:43.000000000 +0300
@@ -54,7 +54,7 @@
 #endif
 
 /* Prototypes */
-dev_t	dev2udev		__P((const struct cdev *dev));
+dev_t	dev2udev		__P((struct cdev *dev));
 int	isofs_filestat		__P((const vnode_t *vp, finfo_t *fsp));
 int	msdosfs_filestat	__P((const vnode_t *vp, finfo_t *fsp));
 int	ufs_filestat		__P((const vnode_t *vp, finfo_t *fsp));
