--- xosd.c	Thu Mar 22 18:55:45 2001
+++ xosd.c.new	Sun May 20 23:13:52 2001
@@ -270,7 +270,7 @@
       if (!XCheckWindowEvent (osd->display, osd->window, ExposureMask, &report))
 	 {
 	 MUTEX_RELEASE ();
-	 usleep (500);
+	 usleep (100000);
 	 continue;
 	 }
       MUTEX_RELEASE ();
@@ -304,7 +304,7 @@
    
    while (!osd->done)
       {
-      usleep (1000);
+      usleep (200000);
       MUTEX_GET ();
       if (osd->timeout != -1 && 
 	  osd->mapped && 
