--- frontpage/version5.0/apache2/mod_fpcgid.c-orig	Fri Jun 27 15:18:28 2003
+++ frontpage/version5.0/apache2/mod_fpcgid.c	Tue Jan 17 18:01:02 2006
@@ -120,8 +120,8 @@
 #include <sys/stat.h>
 #include <sys/un.h> /* for sockaddr_un */
 
-
-module AP_MODULE_DECLARE_DATA frontpage_module; 
+#include "mpm_common.h"
+#include "httpd.h"
 
 #if 0
 This section is not used in the FrontPage daemon.
@@ -187,13 +187,6 @@
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
@@ -685,7 +678,7 @@
                 /* Bad things happened. Everyone should have cleaned up. */
                 ap_log_rerror(APLOG_MARK, APLOG_ERR|APLOG_TOCLIENT, rc, r,
                               "couldn't create child process: %d: %s", rc, 
-                              apr_filename_of_pathname(r->filename));
+                              apr_filepath_name_get(r->filename));
             }
         }
         frontpage_closePipeWrite(&pipe_info);
@@ -755,9 +748,12 @@
 
 void* fpcreate_cgid_config(apr_pool_t *p, server_rec *s) 
 { 
-    cgid_server_conf *c = 
-    (cgid_server_conf *) apr_pcalloc(p, sizeof(cgid_server_conf)); 
+    cgid_server_conf *c;
 
+    c = (cgid_server_conf *) apr_pcalloc(p, sizeof(cgid_server_conf)); 
+
+    c->fp_status = -1;
+    c->fp_admin_status = -1;
     c->logname = NULL; 
     c->logbytes = DEFAULT_LOGBYTES; 
     c->bufbytes = DEFAULT_BUFBYTES; 
@@ -767,9 +763,27 @@
 
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
@@ -823,8 +837,76 @@
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
@@ -935,12 +1017,13 @@
         apr_file_printf(f, "%s\n", sbuf); 
 
     first = 1;
-    APR_BRIGADE_FOREACH(e, bb) {
+    e = APR_BRIGADE_FIRST(bb);
+    while (e != APR_BRIGADE_SENTINEL(bb)) {
         if (APR_BUCKET_IS_EOS(e)) {
             break;
         }
         rv = apr_bucket_read(e, &buf, &len, APR_BLOCK_READ);
-        if (!APR_STATUS_IS_SUCCESS(rv) || (len == 0)) {
+        if ((rv != APR_SUCCESS) || (len == 0)) {
             break;
         }
         if (first) {
@@ -949,6 +1032,7 @@
         }
         apr_file_write(f, buf, &len);
         apr_file_puts("\n", f);
+        e = APR_BUCKET_NEXT(e);
     }
 
     if (script_err) {
@@ -1036,14 +1120,16 @@
     const char *buf;
     apr_size_t len;
     apr_status_t rv;
-    APR_BRIGADE_FOREACH(e, bb) {
+    e = APR_BRIGADE_FIRST(bb);
+    while (e != APR_BRIGADE_SENTINEL(bb)) {
         if (APR_BUCKET_IS_EOS(e)) {
             break;
         }
         rv = apr_bucket_read(e, &buf, &len, APR_BLOCK_READ);
-        if (!APR_STATUS_IS_SUCCESS(rv)) {
+        if (rv != APR_SUCCESS) {
             break;
         }
+        e = APR_BUCKET_NEXT(e);
     }
 }
 
@@ -1179,7 +1265,8 @@
             return rv;
         }
  
-        APR_BRIGADE_FOREACH(bucket, bb) {
+        bucket = APR_BRIGADE_FIRST(bb);
+        while (bucket != APR_BRIGADE_SENTINEL(bb)) {
             const char *data;
             apr_size_t len;
 
@@ -1223,6 +1310,7 @@
                 /* silly script stopped reading, soak up remaining message */
                 child_stopped_reading = 1;
             }
+            bucket = APR_BUCKET_NEXT(bucket);
         }
         apr_brigade_cleanup(bb);
     }
