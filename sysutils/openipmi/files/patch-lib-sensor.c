--- lib/sensor.c.orig	2010-05-28 18:51:20.949496519 +0400
+++ lib/sensor.c	2010-05-28 18:51:37.079705617 +0400
@@ -1438,7 +1438,7 @@
 	    s[p]->id_type = IPMI_ASCII_STR;
 	}
 
-	if (share_count) {
+	if (share_count > 1) {
 	    /* Duplicate the sensor records for each instance.  Go
 	       backwards to avoid destroying the first one until we
 	       finish the others. */
