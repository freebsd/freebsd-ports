--- src/plugins/jabber/jabber_login.c.orig	Fri Oct  7 12:45:32 2005
+++ src/plugins/jabber/jabber_login.c	Fri Oct  7 13:08:49 2005
@@ -42,6 +42,13 @@
 	gchar *jid = g_strdup(ggadu_config_var_get(jabber_handler, "jid"));
 	gchar *server = NULL;
 	gchar *portstr = NULL;
+	gchar **proxy_userpass;
+	gchar **proxy_hostport;
+	gchar **auth;
+	/* proxy setting taken from EKG project */
+	gint jabber_proxy_enabled;
+	gchar jabber_proxy_host;
+	gint jabber_proxy_port;
 
 	g_static_mutex_lock(&connect_mutex);
 	
@@ -98,15 +105,14 @@
 		lm_connection_set_keep_alive_rate(jabber_data.connection,30);
 
 		/* proxy setting taken from EKG project */
-		gint jabber_proxy_enabled = 0;
-		gchar *jabber_proxy_host = NULL;
-		gint jabber_proxy_port;
+		jabber_proxy_enabled = 0;
+		jabber_proxy_host = NULL;
 
 		if (ggadu_config_var_check(jabber_handler, "proxy"))
 		{
-			gchar **auth = array_make((gchar *) ggadu_config_var_get(jabber_handler, "proxy"), "@", 0, 0, 0);
-			gchar **proxy_userpass = NULL;
-			gchar **proxy_hostport = NULL;
+			auth = array_make((gchar *) ggadu_config_var_get(jabber_handler, "proxy"), "@", 0, 0, 0);
+			proxy_userpass = NULL;
+			proxy_hostport = NULL;
 
 			jabber_proxy_enabled = 1;
 
