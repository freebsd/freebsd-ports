--- libgnetwork/gnetwork-tcp-connection.c.orig	Mon May  3 01:29:58 2004
+++ libgnetwork/gnetwork-tcp-connection.c	Mon May  3 01:32:55 2004
@@ -450,6 +450,7 @@
 static void
 open_ssl_connection (GNetworkTcpConnection * connection)
 {
+#ifdef _USE_SSL
   GIOChannel *channel;
   GNetworkSslAuth *auth;
   GError *error;
@@ -517,6 +518,9 @@
   g_object_notify (G_OBJECT (connection), "tcp-status");
   g_object_notify (G_OBJECT (connection), "status");
   g_object_thaw_notify (G_OBJECT (connection));
+#else
+  g_warning ("SSL support not enabled.");
+#endif
 }
 
 
