--- ./modules/proxy/mod_proxy.c.orig	2008-01-03 13:42:06.000000000 +0000
+++ ./modules/proxy/mod_proxy.c	2010-10-21 05:40:53.657622382 +0000
@@ -573,7 +573,7 @@
     struct proxy_remote *new;
     char *p, *q;
     char *r, *f, *scheme;
-    regex_t *reg = NULL;
+    ap_regex_t *reg = NULL;
     int port;
 
     r = apr_pstrdup(cmd->pool, r1);
@@ -603,7 +603,7 @@
         port = -1;
     *p = '\0';
     if (regex) {
-        reg = ap_pregcomp(cmd->pool, f, REG_EXTENDED);
+        reg = ap_pregcomp(cmd->pool, f, AP_REG_EXTENDED);
         if (!reg)
             return "Regular expression for ProxyRemoteMatch could not be compiled.";
     }
@@ -970,7 +970,7 @@
     char *old_path = cmd->path;
     proxy_dir_conf *conf;
     ap_conf_vector_t *new_dir_conf = ap_create_per_dir_config(cmd->pool);
-    regex_t *r = NULL;
+    ap_regex_t *r = NULL;
     const command_rec *thiscmd = cmd->cmd;
 
     const char *err = ap_check_cmd_context(cmd,
@@ -1004,7 +1004,7 @@
      * scheme?  See proxy_fixup()
      */
     if (thiscmd->cmd_data) { /* <ProxyMatch> */
-        r = ap_pregcomp(cmd->pool, cmd->path, REG_EXTENDED);
+        r = ap_pregcomp(cmd->pool, cmd->path, AP_REG_EXTENDED);
         if (!r) {
             return "Regex could not be compiled";
         }
@@ -1015,7 +1015,7 @@
             return "<Proxy ~ > block must specify a path";
         if (strncasecmp(cmd->path, "proxy:", 6))
             cmd->path += 6;
-        r = ap_pregcomp(cmd->pool, cmd->path, REG_EXTENDED);
+        r = ap_pregcomp(cmd->pool, cmd->path, AP_REG_EXTENDED);
         if (!r) {
             return "Regex could not be compiled";
         }
