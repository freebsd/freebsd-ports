--- fuser.c.orig	2006-03-14 14:07:08.000000000 +0300
+++ fuser.c	2009-02-13 02:33:58.000000000 +0300
@@ -65,6 +65,7 @@
  */
 
 #include <stdlib.h>
+#include <stddef.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <string.h>
@@ -88,9 +89,10 @@
 #include <sys/filedesc.h>
 #include <sys/queue.h>
 #include <sys/tty.h>
-#define	_KERNEL
-#include <sys/conf.h>
+#define _WANT_FILE
 #include <sys/file.h>
+#include <sys/conf.h>
+#define _KERNEL
 #include <fs/devfs/devfs.h>
 #include <fs/devfs/devfs_int.h>
 #undef _KERNEL
@@ -717,19 +719,12 @@
  */
 dev_t
 dev2udev(dev)
-	const struct cdev	*dev;
+	struct cdev	*dev;
 {
-	struct cdev		dv;
 	struct cdev_priv	priv;
 	int			ret;
 
-	ret = KVM_READ(kd, dev, &dv, sizeof(struct cdev));
-	if (ret != sizeof(struct cdev)) {
-		warnx("can't read cdev at %p\n", dev);
-		return -1;
-	}
-
-	ret = KVM_READ(kd, dv.si_priv, &priv, sizeof(priv));
+	ret = KVM_READ(kd, cdev2priv(dev), &priv, sizeof(priv));
 	if (ret != sizeof(priv)) {
 		warnx("can't read priv at %p\n", dev);
 		return -1;
