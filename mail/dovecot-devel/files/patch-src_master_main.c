--- src/master/main.c	11 Jun 2006 17:44:25 -0000	1.80.2.2
+++ src/master/main.c	16 Jun 2006 10:11:07 -0000	1.80.2.3
@@ -355,7 +355,9 @@
 	resolve_ip(set->listen, &set->listen_ip, &set->listen_port);
 	resolve_ip(set->ssl_listen, &set->ssl_listen_ip, &set->ssl_listen_port);
 
-	if (set->ssl_listen_ip.family == 0 && set->ssl_listen == NULL)
+	/* if ssl_listen wasn't explicitly set in the config file,
+	   use the non-ssl IP settings for the ssl listener, too. */
+	if (set->ssl_listen_ip.family == 0 && *set->ssl_listen == '\0')
 		set->ssl_listen_ip = set->listen_ip;
 
 	/* register wanted protocols */
