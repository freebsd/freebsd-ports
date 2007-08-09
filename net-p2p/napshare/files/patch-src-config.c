--- src/config.c.orig	2007-08-09 19:31:50.000000000 +0200
+++ src/config.c	2007-08-09 19:32:37.000000000 +0200
@@ -96,7 +96,7 @@
 gchar *proxy_ip = "0.0.0.0";
 gint proxy_port = 1080;
 
-static guint32 gnutella_welcome_length = 0;
+guint32 gnutella_welcome_length = 0;
 
 gchar *socksv5_user = "proxyuser";
 gchar *socksv5_pass = "proxypass";
