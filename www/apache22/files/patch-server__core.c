--- ./server/core.c.orig	2008-06-02 23:18:18.000000000 +0200
+++ ./server/core.c	2009-03-09 15:05:57.000000000 +0100
@@ -494,6 +494,7 @@
     core_server_config *base = (core_server_config *)basev;
     core_server_config *virt = (core_server_config *)virtv;
     core_server_config *conf;
+    const char *accfb, *accfc;
 
     conf = (core_server_config *)apr_pmemdup(p, virt, sizeof(core_server_config));
 
@@ -509,6 +510,25 @@
         conf->protocol = base->protocol;
     }
 
+    /*
+     * bz accept_filter(9) disable fix.
+     *
+     * You can only configure it in the base config but the
+     * values are copied and checked into virtual host configs,
+     * so if you disable it in base it will still be on in virt.
+     * To fix it, we overwrite each virt config if it does not
+     * match what is in base config for the hardcoded http(s).
+     */
+    accfb = apr_table_get(base->accf_map, "http");
+    accfc = apr_table_get(conf->accf_map, "http");
+    if (accfb && accfc && strcmp(accfb, accfc))
+        apr_table_set(conf->accf_map, "http", accfb);
+
+    accfb = apr_table_get(base->accf_map, "https");
+    accfc = apr_table_get(conf->accf_map, "https");
+    if (accfb && accfc && strcmp(accfb, accfc))
+        apr_table_set(conf->accf_map, "https", accfb);
+
     conf->sec_dir = apr_array_append(p, base->sec_dir, virt->sec_dir);
     conf->sec_url = apr_array_append(p, base->sec_url, virt->sec_url);
 
