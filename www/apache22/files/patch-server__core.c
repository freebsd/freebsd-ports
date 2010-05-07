--- ./server/core.c.orig	2009-07-02 17:30:36.000000000 -0400
+++ ./server/core.c	2010-05-06 19:37:54.278731038 -0400
@@ -500,6 +500,7 @@
     core_server_config *base = (core_server_config *)basev;
     core_server_config *virt = (core_server_config *)virtv;
     core_server_config *conf;
+    const char *accfb, *accfc;
 
     conf = (core_server_config *)apr_pmemdup(p, virt, sizeof(core_server_config));
 
@@ -515,6 +516,25 @@
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
 
@@ -2750,7 +2770,7 @@
 AP_DECLARE(const char *) ap_get_server_description(void)
 {
     return server_description ? server_description :
-        AP_SERVER_BASEVERSION " (" PLATFORM ")";
+        AP_SERVER_BASEVERSION " (FreeBSD)";
 }
 
 AP_DECLARE(const char *) ap_get_server_banner(void)
@@ -2811,7 +2831,7 @@
         ap_add_version_component(pconf, AP_SERVER_BASEPRODUCT "/" AP_SERVER_MAJORVERSION);
     }
     else {
-        ap_add_version_component(pconf, AP_SERVER_BASEVERSION " (" PLATFORM ")");
+        ap_add_version_component(pconf, AP_SERVER_BASEVERSION " (FreeBSD)");
     }
 
     /*
@@ -2821,7 +2841,7 @@
     if (ap_server_tokens != SrvTk_FULL) {
         banner_locked++;
     }
-    server_description = AP_SERVER_BASEVERSION " (" PLATFORM ")";
+    server_description = AP_SERVER_BASEVERSION " (FreeBSD)";
 }
 
 static const char *set_serv_tokens(cmd_parms *cmd, void *dummy,
