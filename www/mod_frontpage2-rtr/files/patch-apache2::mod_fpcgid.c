--- frontpage/version5.0/apache2/mod_fpcgid.c.orig	Thu Jan  9 12:19:29 2003
+++ frontpage/version5.0/apache2/mod_fpcgid.c	Wed Feb 12 10:30:45 2003
@@ -121,8 +121,6 @@
 #include <sys/un.h> /* for sockaddr_un */
 
 
-module AP_MODULE_DECLARE_DATA frontpage_module; 
-
 #if 0
 This section is not used in the FrontPage daemon.
 static int cgid_init(apr_pool_t *p, apr_pool_t *plog, apr_pool_t *ptemp, server_rec *main_server); 
@@ -187,13 +185,6 @@
 #define DEFAULT_CONNECT_ATTEMPTS  15
 #endif
 
-typedef struct { 
-    const char *sockname;
-    const char *logname; 
-    long logbytes; 
-    int bufbytes; 
-} cgid_server_conf; 
-
 /* If a request includes query info in the URL (stuff after "?"), and
  * the query info does not contain "=" (indicative of a FORM submission),
  * then this routine is called to create the argument list to be passed
@@ -755,21 +746,42 @@
 
 void* fpcreate_cgid_config(apr_pool_t *p, server_rec *s) 
 { 
-    cgid_server_conf *c = 
-    (cgid_server_conf *) apr_pcalloc(p, sizeof(cgid_server_conf)); 
+    cgid_server_conf *c;
 
-    c->logname = NULL; 
-    c->logbytes = DEFAULT_LOGBYTES; 
-    c->bufbytes = DEFAULT_BUFBYTES; 
-    c->sockname = ap_server_root_relative(p, DEFAULT_SOCKET); 
-    return c; 
+    c = (cgid_server_conf *) apr_pcalloc(p, sizeof(cgid_server_conf)); 
+
+    c->fp_status = -1;
+    c->fp_admin_status = -1;
+    c->logname = NULL; 
+    c->logbytes = DEFAULT_LOGBYTES; 
+    c->bufbytes = DEFAULT_BUFBYTES; 
+    c->sockname = ap_server_root_relative(p, DEFAULT_SOCKET); 
+    return c; 
 } 
 
 void* fpmerge_cgid_config(apr_pool_t *p, void *basev, void *overridesv)
 { 
-    cgid_server_conf *base = (cgid_server_conf *) basev, *overrides = (cgid_server_conf *) overridesv; 
+    cgid_server_conf *c, *base, *overrides;
 
-    return overrides->logname ? overrides : base; 
+    c         = (cgid_server_conf *)apr_pcalloc(p, sizeof(cgid_server_conf));
+    base      = (cgid_server_conf *)basev;
+    overrides = (cgid_server_conf *)overridesv; 
+
+    c->fp_status = (overrides->fp_status == -1) ? base->fp_status : overrides->fp_status;
+    c->fp_admin_status = (overrides->fp_admin_status == -1) ? base->fp_admin_status : overrides->fp_admin_status;
+
+    if (overrides->logname) {
+	c->logname = apr_pstrdup(p, overrides->logname);
+	c->logbytes = overrides->logbytes ? overrides->logbytes : base->logbytes;
+	c->bufbytes = overrides->bufbytes ? overrides->bufbytes : base->bufbytes;
+	c->sockname = apr_pstrdup(p, overrides->sockname ? overrides->sockname : base->sockname);
+    } else {
+	c->logname = apr_pstrdup(p, base->logname);
+	c->logbytes = base->logbytes;
+	c->bufbytes = base->bufbytes;
+	c->sockname = apr_pstrdup(p, base->sockname);
+    }
+    return c;
 } 
 
 static const char *set_scriptlog(cmd_parms *cmd, void *dummy, const char *arg) 
@@ -823,8 +835,76 @@
     return NULL; 
 } 
 
+static const char *
+cmd_FrontPage(cmd_parms *cmd, void *mconfig, int flag)
+{
+    cgid_server_conf *sconf;
+
+    sconf = (cgid_server_conf *)ap_get_module_config(cmd->server->module_config, &frontpage_module);
+
+    if (cmd->path == NULL) { /* is server command */
+       sconf->fp_status = (flag ? TRUE : FALSE);
+    }
+    return NULL;
+}
+
+#ifdef IMPROVED_MODFP_COMPAT
+static const char*
+cmd_disable(cmd_parms* cmd, void* mconfig) {
+
+        return cmd_FrontPage(cmd, NULL, FALSE);
+}
+
+static const char*
+cmd_enable(cmd_parms* cmd, void* mconfig) {
+
+    return cmd_FrontPage(cmd, NULL, TRUE);    
+}
+#endif /* IMPROVED_MODFP_COMPAT */
+
+static const char *
+cmd_FrontPageAdmin(cmd_parms *cmd, void *mconfig, int flag)
+{  
+    cgid_server_conf *sconf;
+
+    sconf = (cgid_server_conf *)ap_get_module_config(cmd->server->module_config, &frontpage_module);
+
+    if (cmd->path == NULL) { /* is server command */
+        sconf->fp_admin_status = (flag ? TRUE : FALSE);
+    }
+    return NULL;
+}
+
+#ifdef IMPROVED_MODFP_COMPAT
+static const char*
+cmd_admin_disable(cmd_parms* cmd, void* mconfig) {
+
+        return cmd_FrontPageAdmin(cmd, NULL, TRUE);
+}
+
+static const char*
+cmd_admin_enable(cmd_parms* cmd, void *mconfig) {
+
+    return cmd_FrontPageAdmin(cmd, NULL, FALSE);
+}
+#endif /* IMPROVED_MODFP_COMPAT */
+
 const command_rec fpcgid_cmds[] =
 {
+    AP_INIT_FLAG("FrontPage", cmd_FrontPage, NULL, RSRC_CONF,
+		"On or Off to enable (default) or disable the FrontPage Extentions"),
+    AP_INIT_FLAG("FrontPageAdmin", cmd_FrontPageAdmin, NULL, RSRC_CONF,
+		"On or Off to enable (default) or disable FrontPage Administration"),
+#ifdef IMPROVED_MODFP_COMPAT
+    AP_INIT_NO_ARGS("FrontPageDisable", cmd_disable, NULL, RSRC_CONF,
+		"Disable FrontPage Extentions"),
+    AP_INIT_NO_ARGS("FrontPageEnable", cmd_enable, NULL, RSRC_CONF,
+		"Enable FrontPage Extentions"),
+    AP_INIT_NO_ARGS("FrontPageAdminDisable", cmd_admin_disable, NULL, RSRC_CONF,
+		"Disable FrontPage Administration"),
+    AP_INIT_NO_ARGS("FrontPageAdminEnable", cmd_admin_enable, NULL, RSRC_CONF,
+                "Enable FrontPage Administration"),
+#endif
     AP_INIT_TAKE1("FPScriptLog", set_scriptlog, NULL, RSRC_CONF,
                   "the name of a log for script debugging info"),
     AP_INIT_TAKE1("FPScriptLogLength", set_scriptlog_length, NULL, RSRC_CONF,
