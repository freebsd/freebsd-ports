--- src/libxosd/xosd.c.orig	Mon Jul  5 02:29:06 2004
+++ src/libxosd/xosd.c	Sun Jul 11 06:30:47 2004
@@ -432,7 +432,7 @@
   FUNCTION_START;
   DEBUG("event thread started");
   assert(osd);
-  usleep(500);
+  usleep(100000);
 
   while (!osd->done) {
     // DEBUG("checking window event");
