--- avahi-daemon/main.c.orig	2010-11-18 03:00:26 UTC
+++ avahi-daemon/main.c
@@ -320,6 +320,11 @@ static void update_browse_domains(void) 
         return;
     }
 
+    if (!resolv_conf_search_domains) {
+	    avahi_server_set_browse_domains(avahi_server, NULL);
+	    return;
+    }
+
     l = avahi_string_list_copy(config.server_config.browse_domains);
 
     for (p = resolv_conf_search_domains, n = 0; *p && n < BROWSE_DOMAINS_MAX; p++, n++) {
