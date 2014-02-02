--- ./mod_limitipconn.c.orig	2012-04-26 00:19:48.000000000 +0200
+++ ./mod_limitipconn.c	2014-02-02 16:47:28.000000000 +0100
@@ -42,6 +42,9 @@
     /* array of MIME types to limit check; all other types are exempt */
     apr_array_header_t *excl_limit;
 
+    apr_array_header_t *local_ip;   /* array of local ip exempt from limit
+    				checking */
+
 } limitipconn_config;
 
 static limitipconn_config *create_config(apr_pool_t *p)
@@ -53,6 +56,7 @@
     cfg->limit = 0;
     cfg->no_limit = apr_array_make(p, 0, sizeof(char *));
     cfg->excl_limit = apr_array_make(p, 0, sizeof(char *));
+    cfg->local_ip = apr_array_make(p, 0, sizeof(char *));
 
     return cfg;
 }
@@ -75,6 +79,7 @@
     /* convert Apache arrays to normal C arrays */
     char **nolim = (char **) cfg->no_limit->elts;
     char **exlim = (char **) cfg->excl_limit->elts;
+    char **localip = (char **) cfg->local_ip->elts;
 
     const char *address;
 
@@ -112,7 +117,7 @@
 
     /* Only check the MIME-type if we have MIME-type stuff in our config.
        The extra subreq can be quite expensive. */
-    if(cfg->no_limit->nelts > 0 || cfg->excl_limit->nelts > 0) {
+    if(cfg->no_limit->nelts > 0 || cfg->excl_limit->nelts > 0 || cfg->local_ip->nelts) {
         /* Look up the Content-type of this request. We need a subrequest
          * here since this module might be called before the URI has been
          * translated into a MIME type. */
@@ -129,6 +134,20 @@
                 "mod_limitipconn: uri: %s  Content-Type: %s", 
                 r->uri, content_type);
 
+     	/* Cycle through the local ip list; if the ip is local,
+     	 * return OK */
+
+     	for (i = 0; i < cfg->local_ip->nelts; i++) {
+	  ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r,
+	  	"mod_limitipconn: ip check: \"%s\" ? \"%s\"", address, localip[i]);
+     	  if ((ap_strcasecmp_match(address, localip[i]) == 0)
+     	      || (strncmp(localip[i], address, strlen(localip[i])) == 0)) {
+	      ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r,
+	      	"mod_limitipconn: ip exempt: %s", address);
+     	      return DECLINED;
+     	  }
+     	}
+
         /* Cycle through the exempt list; if our content_type is exempt,
          * return OK */
 #if AP_MODULE_MAGIC_AT_LEAST(20090131, 0)
@@ -328,6 +347,24 @@
     return NULL;
 }
 
+/* Parse the LocalIP directive */
+static const char *local_ip_config_cmd(cmd_parms *parms, void *mconfig,
+					 const char *arg)
+{
+    limitipconn_config *cfg = (limitipconn_config *) mconfig;
+    limitipconn_config *scfg = (limitipconn_config *)
+      ap_get_module_config(parms->server->module_config, &limitipconn_module);
+
+    if (parms->path != NULL) {
+      /* Per-directory context */
+      *(char **) apr_array_push(cfg->local_ip) = apr_pstrdup(parms->pool, arg);
+    } else {
+      /* global context */
+      *(char **) apr_array_push(scfg->local_ip) = apr_pstrdup(parms->pool, arg);
+    }
+    return NULL;
+}
+
 /* Array describing structure of configuration directives */
 static command_rec limitipconn_cmds[] = {
     AP_INIT_TAKE1("MaxConnPerIP", limit_config_cmd, NULL, OR_LIMIT|RSRC_CONF,
@@ -336,6 +373,8 @@
      "MIME types for which limit checking is disabled"),
     AP_INIT_ITERATE("OnlyIPLimit", excl_limit_config_cmd, NULL,
      OR_LIMIT|RSRC_CONF, "restrict limit checking to these MIME types only"),
+     AP_INIT_ITERATE("LocalIP", local_ip_config_cmd, NULL, OR_LIMIT|RSRC_CONF,
+           "no checking on local IP"),
     {NULL},
 };
 
