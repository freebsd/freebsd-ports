--- libng/plugins/drv0-bsd.c.orig	Wed Feb 11 23:13:04 2004
+++ libng/plugins/drv0-bsd.c	Wed Feb 11 23:13:10 2004
@@ -23,10 +23,12 @@
 
 #ifdef HAVE_DEV_IC_BT8XX_H
 # include <dev/ic/bt8xx.h>
-#endif
-#ifdef HAVE_MACHINE_IOCTL_BT848_H
+#elif defined(HAVE_MACHINE_IOCTL_BT848_H)
 # include <machine/ioctl_bt848.h>
 # include <machine/ioctl_meteor.h>
+#else
+# include <dev/bktr/ioctl_bt848.h>
+# include <dev/bktr/ioctl_meteor.h>
 #endif
 
 #include "grab-ng.h"
@@ -599,7 +599,15 @@
 
 static int bsd_tuned(void *handle)
 {
-    return 0;
+    struct bsd_handle *h = handle;
+    int signal;
+
+    usleep(10000);
+
+    if (-1 == xioctl(h->tfd, TVTUNER_GETSTATUS, &signal))
+	return 0;
+
+    return signal == 106 ? 1 : 0;
 }
 
 /* ---------------------------------------------------------------------- */
