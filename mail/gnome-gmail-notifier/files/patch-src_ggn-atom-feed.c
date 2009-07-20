--- src/ggn-atom-feed.c.orig	2008-01-11 00:41:24.000000000 +0900
+++ src/ggn-atom-feed.c	2009-04-25 16:24:07.000000000 +1000
@@ -75,7 +75,7 @@
     /* the libsoup session and proxy. */
     SoupSession* session;
     SoupMessage* message;
-    SoupUri* proxy;
+    SoupURI* proxy;
     
     /* the username and password. */
     gchar* name;
@@ -129,25 +129,17 @@
  */
 static gboolean ggn_atom_feed_auth (SoupSession* session,
                                     SoupMessage* message,
-                                    gchar* auth_type,
-                                    gchar* auth_realm,
-                                    gchar** username,
-                                    gchar** password,
+                                    SoupAuth* auth,
+                                    gboolean retrying,
                                     gpointer data) {
     /* the userdata is the gobject. */
     GgnAtomFeed* feed = GGN_ATOM_FEED (data);
     
-    /* see if we can set the username. */
-    if (feed->priv->user != NULL) {
-        /* set the username. */
-        *username = g_strdup (feed->priv->user);
-    }
-    
-    /* see if we can set the password. */
-    if (feed->priv->pass != NULL) {
-        /* set the username. */
-        *password = g_strdup (feed->priv->pass);
+    /* see if we can set the username and password. */
+    if (feed->priv->user != NULL && feed->priv->pass != NULL) {
+		soup_auth_authenticate (auth, g_strdup (feed->priv->user), g_strdup (feed->priv->pass));
     }
+
     
     /* exit our function. */
     return TRUE;
@@ -299,7 +291,7 @@
     g_signal_connect (G_OBJECT (self->priv->session),
                       "authenticate",
                       G_CALLBACK (ggn_atom_feed_auth),
-                      (gpointer) self);
+                      self);
     
     /* setup the parser object. */
     self->priv->parser = ggn_xml_parser_new ();
@@ -495,12 +487,14 @@
     feed->priv->proxy = soup_uri_new (feed->priv->prox);
     
     /* refresh the proxy-uri property of the session */
-    GValue val = {0,};
-    g_value_init (&val, G_TYPE_POINTER);
-    g_value_set_pointer (&val, feed->priv->proxy);
-    g_object_set_property (G_OBJECT (feed->priv->session),
-                           SOUP_SESSION_PROXY_URI,
-                           &val);
+	if (feed->priv->proxy != NULL) {
+		GValue val = {0,};
+		g_value_init (&val, G_TYPE_POINTER);
+		g_value_set_pointer (&val, feed->priv->proxy);
+		g_object_set_property (G_OBJECT (feed->priv->session),
+							   SOUP_SESSION_PROXY_URI,
+							   &val);
+	}
 }
 
 /*
@@ -679,7 +673,9 @@
     /* check the return value. */
     if (retval == 200) {
         /* we got the feed. */
-        gchar* body = g_strdup (self->priv->message->response.body);
+		SoupMessageBody* msgbody = self->priv->message->response_body;
+		soup_message_body_flatten (msgbody);
+        gchar* body = g_strdup (msgbody->data);
         
         /* see if we must free the message array. */
         if (self->priv->box.msgs != NULL) {
@@ -712,7 +708,7 @@
     }
     
     /* close all open and unused connections. */
-    soup_session_try_prune_connection (self->priv->session);
+    soup_session_abort (self->priv->session);
     
     /* emit the "updated" signal. */
     g_signal_emit (feed, signals[UPDATED], 0, status);
