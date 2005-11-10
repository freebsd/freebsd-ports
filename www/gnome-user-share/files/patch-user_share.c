--- user_share.c.orig	Tue Nov  8 10:41:50 2005
+++ user_share.c	Thu Nov 10 13:38:07 2005
@@ -252,8 +252,8 @@ howl_input (GIOChannel  *io_channel,
 			gpointer     callback_data)
 {
 	sw_discovery session;
-	session = callback_data;
 	sw_salt salt;
+	session = callback_data;
 
 	if (sw_discovery_salt (session, &salt) == SW_OKAY) {
 		sw_salt_lock (salt);
@@ -301,7 +301,6 @@ publish_service (int port)
 								   /* TODO: should be u=guest */
 								   /* text */ (unsigned char *) "", 0,
 								   publish_reply, NULL, &published_id);
-    g_free (share_name);
     if (result != SW_OKAY) {
 		return FALSE;
     }
