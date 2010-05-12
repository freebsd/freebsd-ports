--- modules/metadata/mod_remoteip.c.orig	2010-05-11 21:33:43.631571954 -0500
+++ modules/metadata/mod_remoteip.c	2010-05-11 21:34:15.374903181 -0500
@@ -127,7 +127,7 @@
     return (*ipstr == '\0');
 }
 
-static const char *proxies_set(cmd_parms *cmd, void *internal,
+static const char *proxies_set(cmd_parms *cmd, void *cfg,
                                const char *arg)
 {
     remoteip_config_t *config = ap_get_module_config(cmd->server->module_config,
@@ -142,7 +142,7 @@
     if (!config->proxymatch_ip)
         config->proxymatch_ip = apr_array_make(cmd->pool, 1, sizeof(*match));
     match = (remoteip_proxymatch_t *) apr_array_push(config->proxymatch_ip);
-    match->internal = internal;
+    match->internal = cmd->info;
 
     if (looks_like_ip(ip)) {
         /* Note s may be null, that's fine (explicit host) */
@@ -168,7 +168,7 @@
                 break;
             match = (remoteip_proxymatch_t *) 
                     apr_array_push(config->proxymatch_ip);
-            match->internal = internal;
+            match->internal = cmd->info;
         }
     }
 
@@ -182,7 +182,7 @@
     return NULL;
 }
 
-static const char *proxylist_read(cmd_parms *cmd, void *internal,
+static const char *proxylist_read(cmd_parms *cmd, void *cfg,
                                   const char *filename)
 {
     char lbuf[MAX_STRING_LEN];
@@ -205,7 +205,7 @@
         while (*(arg = ap_getword_conf(cmd->temp_pool, &args)) != '\0') {
             if (*arg == '#' || *arg == '\0')
                 break;
-            errmsg = proxies_set(cmd, internal, arg);
+            errmsg = proxies_set(cmd, cfg, arg);
             if (errmsg) {
                 errmsg = apr_psprintf(cmd->pool, "%s at line %d of %s", 
                                       errmsg, cfp->line_number, filename);
