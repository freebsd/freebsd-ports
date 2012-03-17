--- src/gvnc.c.orig	2012-03-17 12:30:12.000000000 -0500
+++ src/gvnc.c	2012-03-17 12:31:37.000000000 -0500
@@ -3543,7 +3543,7 @@
 		gvnc->minor = 8;
 	}
 
-	snprintf(version, 12, "RFB %03d.%03d\n", gvnc->major, gvnc->minor);
+	snprintf(version, 13, "RFB %03d.%03d\n", gvnc->major, gvnc->minor);
 	gvnc_write(gvnc, version, 12);
 	gvnc_flush(gvnc);
 	GVNC_DEBUG("Using version: %d.%d", gvnc->major, gvnc->minor);
