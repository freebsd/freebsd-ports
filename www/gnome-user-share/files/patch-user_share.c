--- user_share.c.orig	Sat Dec  4 04:34:24 2004
+++ user_share.c	Sat Dec  4 04:35:05 2004
@@ -103,8 +103,8 @@
 	    gpointer     callback_data)
 {
 	sw_discovery session;
-	session = callback_data;
 	sw_salt salt;
+	session = callback_data;
 
 	if (sw_discovery_salt (session, &salt) == SW_OKAY) {
 		sw_salt_lock (salt);
