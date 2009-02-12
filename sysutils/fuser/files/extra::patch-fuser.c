--- fuser.c.orig	2009-02-13 02:11:34.000000000 +0300
+++ fuser.c	2009-02-13 02:19:21.000000000 +0300
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
@@ -729,7 +731,7 @@
 		return -1;
 	}
 
-	ret = KVM_READ(kd, dv.si_priv, &priv, sizeof(priv));
+	ret = KVM_READ(kd, cdev2priv(&dv), &priv, sizeof(priv));
 	if (ret != sizeof(priv)) {
 		warnx("can't read priv at %p\n", dev);
 		return -1;
