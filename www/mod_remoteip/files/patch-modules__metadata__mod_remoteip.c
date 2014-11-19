--- modules/metadata/mod_remoteip.c.orig	2009-05-05 18:52:59 UTC
+++ modules/metadata/mod_remoteip.c
@@ -127,7 +127,7 @@ static int looks_like_ip(const char *ips
     return (*ipstr == '\0');
 }
 
-static const char *proxies_set(cmd_parms *cmd, void *internal,
+static const char *proxies_set(cmd_parms *cmd, void *cfg,
                                const char *arg)
 {
     remoteip_config_t *config = ap_get_module_config(cmd->server->module_config,
@@ -142,7 +142,7 @@ static const char *proxies_set(cmd_parms
     if (!config->proxymatch_ip)
         config->proxymatch_ip = apr_array_make(cmd->pool, 1, sizeof(*match));
     match = (remoteip_proxymatch_t *) apr_array_push(config->proxymatch_ip);
-    match->internal = internal;
+    match->internal = cmd->info;
 
     if (looks_like_ip(ip)) {
         /* Note s may be null, that's fine (explicit host) */
@@ -168,7 +168,7 @@ static const char *proxies_set(cmd_parms
                 break;
             match = (remoteip_proxymatch_t *) 
                     apr_array_push(config->proxymatch_ip);
-            match->internal = internal;
+            match->internal = cmd->info;
         }
     }
 
@@ -182,7 +182,7 @@ static const char *proxies_set(cmd_parms
     return NULL;
 }
 
-static const char *proxylist_read(cmd_parms *cmd, void *internal,
+static const char *proxylist_read(cmd_parms *cmd, void *cfg,
                                   const char *filename)
 {
     char lbuf[MAX_STRING_LEN];
@@ -205,7 +205,7 @@ static const char *proxylist_read(cmd_pa
         while (*(arg = ap_getword_conf(cmd->temp_pool, &args)) != '\0') {
             if (*arg == '#' || *arg == '\0')
                 break;
-            errmsg = proxies_set(cmd, internal, arg);
+            errmsg = proxies_set(cmd, cfg, arg);
             if (errmsg) {
                 errmsg = apr_psprintf(cmd->pool, "%s at line %d of %s", 
                                       errmsg, cfp->line_number, filename);
@@ -260,7 +260,7 @@ static int remoteip_modify_connection(re
     remote = apr_pstrdup(r->pool, remote);
 
 #ifdef REMOTEIP_OPTIMIZED
-    memcpy(&temp_sa, c->remote_addr, sizeof(temp_sa));
+    memcpy(temp_sa, c->remote_addr, sizeof(*temp_sa));
     temp_sa->pool = r->pool;
 #else
     temp_sa = c->remote_addr;
@@ -310,7 +310,7 @@ static int remoteip_modify_connection(re
 #ifdef REMOTEIP_OPTIMIZED
         /* Decode remote_addr - sucks; apr_sockaddr_vars_set isn't 'public' */
         if (inet_pton(AF_INET, parse_remote, 
-                      &temp_sa_buff->sa.sin.sin_addr) > 0) {
+                      &temp_sa->sa.sin.sin_addr) > 0) {
             apr_sockaddr_vars_set(temp_sa, APR_INET, temp_sa.port);
         }
 #if APR_HAVE_IPV6
@@ -409,7 +409,7 @@ static int remoteip_modify_connection(re
      */
     c->remote_ip = apr_pstrdup(c->pool, c->remote_ip);
     conn->proxied_ip = c->remote_ip;
-    memcpy(&conn->proxied_addr, &temp_sa, sizeof(temp_sa));
+    memcpy(&conn->proxied_addr, temp_sa, sizeof(*temp_sa));
     conn->proxied_addr.pool = c->pool;
     c->remote_addr = &conn->proxied_addr;
 
