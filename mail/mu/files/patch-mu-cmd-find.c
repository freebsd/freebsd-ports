--- src/mu-cmd-find.c.orig	2012-03-02 23:03:51.892426975 +0400
+++ src/mu-cmd-find.c	2012-03-02 23:04:27.156423697 +0400
@@ -476,7 +476,7 @@
 		return FALSE;
 	}
 
-	if (count) {
+	if (!count) {
 		g_set_error (err, 0, MU_ERROR_NO_MATCHES,
 			     "no existing matches for search expression");
 		return FALSE;
