--- libng/plugins/drv0-bsd.c.orig	Wed Feb 11 23:13:04 2004
+++ libng/plugins/drv0-bsd.c	Wed Feb 11 23:13:10 2004
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
