--- src/libxosd/xosd.c.orig	Fri Sep 26 09:25:42 2003
+++ src/libxosd/xosd.c	Sun Sep 28 01:30:28 2003
@@ -377,7 +377,7 @@
 
   DEBUG ("event thread started");
   assert (osd);
-  usleep (500);
+  usleep (100000);
 
   while (!osd->done)
     {
