--- src/libxosd/xosd.c.orig	Wed Sep 18 19:52:22 2002
+++ src/libxosd/xosd.c	Wed Sep 18 19:53:00 2002
@@ -198,7 +198,7 @@
     pthread_mutex_lock (&osd->mutex);
     if (!XCheckWindowEvent (osd->display, osd->window, ExposureMask, &report)) {
       pthread_mutex_unlock (&osd->mutex);
-      usleep (500);
+      usleep (100000);
       continue;
     }
     pthread_mutex_unlock (&osd->mutex);
@@ -242,7 +242,7 @@
   if (osdv == NULL) return NULL;
 
   while (!osd->done) {
-    usleep (1000);
+    usleep (200000);
     pthread_mutex_lock (&osd->mutex);
     if (osd->timeout != -1 && osd->mapped && osd->timeout_time <= time(NULL)) {
       pthread_mutex_unlock (&osd->mutex);
