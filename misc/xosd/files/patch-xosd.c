--- src/libxosd/xosd.c.orig	Wed Feb 19 10:53:59 2003
+++ src/libxosd/xosd.c	Mon Mar 31 14:00:23 2003
@@ -332,7 +332,7 @@
 
 	DEBUG("event thread started");
	assert (osd);
-	usleep (500);
+	usleep (100000);
 
	while (!osd->done) {
		//DEBUG("checking window event");
