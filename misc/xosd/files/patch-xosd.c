--- src/xosd.c.orig	Fri Aug  9 13:49:59 2002
+++ src/xosd.c	Fri Aug  9 13:50:30 2002
@@ -291,7 +291,7 @@
       if (!XCheckWindowEvent (osd->display, osd->window, ExposureMask, &report))
 	 {
 	   MUTEX_RELEASE ();
-	   usleep (500);
+	   usleep (100000);
 	   continue;
 	 }
       MUTEX_RELEASE ();
@@ -326,7 +326,7 @@
 
    while (!osd->done)
       {
-      usleep (1000);
+      usleep (200000);
       MUTEX_GET ();
       if (osd->timeout != -1 && 
 	  osd->mapped && 
