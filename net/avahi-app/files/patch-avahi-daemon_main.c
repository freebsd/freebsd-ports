--- avahi-daemon/main.c.orig	2007-08-26 00:48:40.000000000 -0400
+++ avahi-daemon/main.c	2007-08-26 00:49:04.000000000 -0400
@@ -317,6 +317,11 @@ static void update_browse_domains(void) 
     int n;
     char **p;
 
+    if (!resolv_conf_search_domains) {
+	    avahi_server_set_browse_domains(avahi_server, NULL);
+	    return;
+    }
+
     l = avahi_string_list_copy(config.server_config.browse_domains);
     
     for (p = resolv_conf_search_domains, n = 0; *p && n < BROWSE_DOMAINS_MAX; p++, n++) {
