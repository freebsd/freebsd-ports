--- libseahorse/seahorse-server-source.c.orig	Fri Mar 11 22:17:43 2005
+++ libseahorse/seahorse-server-source.c	Fri Mar 11 22:17:55 2005
@@ -518,11 +518,11 @@
 seahorse_server_source_get_state (SeahorseKeySource *src)
 {
     SeahorseServerSource *ssrc;
+    guint state = SEAHORSE_KEY_SOURCE_REMOTE;
     
     g_return_val_if_fail (SEAHORSE_IS_SERVER_SOURCE (src), 0);
     ssrc = SEAHORSE_SERVER_SOURCE (src);
     
-    guint state = SEAHORSE_KEY_SOURCE_REMOTE;
     if (!seahorse_operation_is_done (ssrc->priv->operation))
         state |= SEAHORSE_KEY_SOURCE_LOADING;
     return state;
