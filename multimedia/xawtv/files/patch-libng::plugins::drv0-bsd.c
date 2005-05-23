--- libng/plugins/drv0-bsd.c.orig	Wed Mar 12 17:45:56 2003
+++ libng/plugins/drv0-bsd.c	Mon May 23 17:01:27 2005
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
@@ -502,10 +504,11 @@
 static int bsd_read_attr(struct ng_attribute *attr)
 {
     struct bsd_handle *h = attr->handle;
-    int arg, get, set, i;
+    int get, set, i;
+    long arg;
     int value = -1;
 
     switch (attr->id) {
     case ATTR_ID_NORM:
 	if (-1 != xioctl(h->fd,BT848GFMT,&arg))
 	    for (i = 0; i < sizeof(norms_map)/sizeof(int); i++)
@@ -599,7 +605,15 @@
 
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
