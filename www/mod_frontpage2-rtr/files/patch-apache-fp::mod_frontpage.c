--- frontpage/version5.0/apache-fp/mod_frontpage.c.orig	Tue Dec  2 20:18:45 2003
+++ frontpage/version5.0/apache-fp/mod_frontpage.c	Mon Jan 31 00:43:54 2005
@@ -52,10 +52,13 @@
 #include "httpd.h"
 #include "http_config.h"
 #include "http_conf_globals.h"
+#include "http_log.h"
 
 #include <stdio.h>
 #include <sys/time.h>
 
+module MODULE_VAR_EXPORT frontpage_module;
+
 #ifndef TRUE
 #define TRUE 1
 #endif
@@ -74,6 +77,11 @@
 
 #define KEYLEN 128                  /* Should be a multiple of sizeof(int) */
 
+typedef struct {
+        int fp_status;
+        int fp_admin_status;
+} FrontPage_conf;
+
 static char gszKeyVal[KEYLEN+1];    /* SUID key value used by this module */
 static int  gfdKeyPipe[2];          /* Pipe to fpexe stub CGI */
 static int  gbKeyPipeActive;        /* Pipe to fpexe stub CGI is active */
@@ -584,6 +592,31 @@
      * Thanks to Scot Hetzel (hetzels@westbend.net)
      */
     ap_add_version_component("FrontPage/5.0.2.2635");
+
+    while (s != NULL) {
+        FrontPage_conf* c = ap_get_module_config (s->module_config, &frontpage_module);
+        if (c->fp_status == -1)
+#ifdef DEFAULT_TO_OFF
+	    c->fp_status = FALSE;
+#else
+	    c->fp_status = TRUE;
+#endif
+        if (!c->fp_status)
+            ap_log_error (APLOG_MARK, APLOG_DEBUG|APLOG_NOERRNO, s,
+                          "FrontPage disabled for server %s:%d\n",
+                          s->server_hostname, s->port);
+	if (c->fp_admin_status == -1)
+#ifdef DEFAULT_TO_OFF
+	    c->fp_admin_status = FALSE;
+#else
+	    c->fp_admin_status = TRUE;
+#endif
+	if (!c->fp_admin_status)
+	    ap_log_error (APLOG_MARK, APLOG_DEBUG|APLOG_NOERRNO, s,
+			  "FrontPage Administration pages disabled for server %s:%d\n",
+			  s->server_hostname, s->port);
+        s = s->next;
+    }
 }
 
 static int FrontPageCheckWebRoot(
@@ -793,6 +826,26 @@
     return OK;
 }
 
+/*
+ * We *MUST* have been authenticated somehow for AUTHOR or ADMIN requests.
+ * This prevents the single largest hole in FrontPage: if the user somehow
+ * deletes their .htaccess files anyone can gain FrontPage AUTHOR or ADMIN
+ * privileges.  With this check we won't allow ADMIN or AUTHOR unless _some_
+ * authentication was performed.
+ */
+static int FrontPageNeedAuth(
+    request_rec* r,
+    char* szCgi,
+    const char* szFpexe)
+{
+    if ((r->connection->user == NULL) || (r->connection->ap_auth_type == NULL)) {
+	ap_log_rerror(APLOG_MARK, APLOG_NOERRNO|APLOG_ERR, r,
+	     "server configuration did not require authentication: %s", r->filename);
+	return FORBIDDEN;
+    } else {
+	return FrontPageAlias(r, szCgi, szFpexe);
+    }
+}
 
 /*
  * This routine looks for shtml.exe, fpcount.exe, author.exe and admin.exe
@@ -806,6 +859,7 @@
 {
     char *szVti;
     char *szCgi;
+    FrontPage_conf *c;
     char szBuf[MAXPATHLEN];
 
     /*
@@ -815,6 +869,13 @@
         return DECLINED;
 
     /*
+     * Decline if we have disabled FrontPage on the server.
+     */
+    c = (FrontPage_conf *)ap_get_module_config (r->server->module_config, &frontpage_module);
+	if (!c->fp_status)
+	    return FORBIDDEN;
+
+    /*
      * Check once for anything with _vti_bin.  This is much faster than
      * checking all our paths, because anything without this is definitely
      * not a FrontPage scenario.
@@ -835,7 +896,7 @@
         return FrontPageAlias(r, szCgi, AUTHOR);
     /*
      * Convert inadvertent shtml.dll to shtml.exe
-     * Thanks for the idea to Scot Hetzel (hetzels@westbend.net)
+     * Thanks for the idea from Scot Hetzel (hetzels@westbend.net)
      */
     if (szCgi = strstr(szVti, SHTML2 ))
     {
@@ -845,9 +906,17 @@
     if (szCgi = strstr(szVti, SHTML  ))
         return FrontPageAlias(r, szCgi, SHTML);
     if (szCgi = strstr(szVti, ADMIN  ))
-        return FrontPageAlias(r, szCgi, ADMIN);
+	if (c->fp_admin_status) {
+            return FrontPageAlias(r, szCgi, ADMIN);
+	} else {
+	    return FORBIDDEN;
+	}
     if (szCgi = strstr(szVti, ADMINCGI  ))
-        return FrontPageAlias(r, szCgi, ADMINCGI);
+	if (c->fp_admin_status) {
+            return FrontPageAlias(r, szCgi, ADMINCGI);
+	} else {
+	    return FORBIDDEN;
+	}
     if (szCgi = strstr(szVti, FPCOUNT))
         return FrontPageAlias(r, szCgi, FPCOUNT);
 
@@ -916,6 +985,100 @@
     return OK;
 }
 
+static void*
+FrontPageCreate_config(pool* p, server_rec* s) {
+        FrontPage_conf* new = (FrontPage_conf *)ap_pcalloc (p, sizeof (FrontPage_conf));
+        new->fp_status = -1;
+        new->fp_admin_status = -1;
+        return new;
+} 
+ 
+static void*
+FrontPageMerge_config(pool* p, void* basev, void* addv) {
+    FrontPage_conf *base = (FrontPage_conf *)basev;
+    FrontPage_conf *add  = (FrontPage_conf *)addv;
+    FrontPage_conf *new  = (FrontPage_conf *)ap_pcalloc (p, sizeof (FrontPage_conf));
+    new->fp_status = (add->fp_status == -1) ? base->fp_status : add->fp_status;
+    new->fp_admin_status = (add->fp_admin_status == -1) ? base->fp_admin_status : add->fp_admin_status;
+    return new;
+}
+
+static const char *
+cmd_FrontPage(cmd_parms *cmd, void *dummy, int flag)
+{
+    FrontPage_conf *sconf;
+
+    sconf = (FrontPage_conf *)ap_get_module_config(cmd->server->module_config, &frontpage_module);
+
+    if (cmd->path == NULL) { /* is server command */
+	sconf->fp_status = (flag ? TRUE : FALSE);
+    }
+    return NULL;
+}
+
+#ifdef IMPROVED_MODFP_COMPAT
+static const char*
+cmd_disable(cmd_parms* cmd, char* struct_ptr) {
+
+        return cmd_FrontPage(cmd, NULL, FALSE);
+}
+
+static const char*
+cmd_enable(cmd_parms* cmd, char* struct_ptr) {
+                                          
+    return cmd_FrontPage(cmd, NULL, TRUE);     
+}
+#endif /* IMPROVED_MODFP_COMPAT */
+
+static const char *
+cmd_FrontPageAdmin(cmd_parms *cmd, void *dummy, int flag)
+{   
+    FrontPage_conf *sconf;
+
+    sconf = (FrontPage_conf *)ap_get_module_config(cmd->server->module_config, &frontpage_module);
+
+    if (cmd->path == NULL) { /* is server command */
+        sconf->fp_admin_status = (flag ? TRUE : FALSE);
+    }
+    return NULL;
+}
+
+#ifdef IMPROVED_MODFP_COMPAT
+static const char*
+cmd_admin_disable(cmd_parms* cmd, char* struct_ptr) {
+
+        return cmd_FrontPageAdmin(cmd, NULL, TRUE);
+}
+
+static const char*
+cmd_admin_enable(cmd_parms* cmd, char* struct_ptr) {
+
+    return cmd_FrontPageAdmin(cmd, NULL, FALSE);
+}
+#endif /* IMPROVED_MODFP_COMPAT */
+
+static const
+command_rec FrontPageCMDs[] = {
+	{ "FrontPage", cmd_FrontPage, NULL, RSRC_CONF, FLAG,
+	"On or Off to enable (default) or disable the FrontPage User Access" },
+	{ "FrontPageAdmin", cmd_FrontPageAdmin, NULL, RSRC_CONF, FLAG,
+	"On or Off to enable (default) or disable the FrontPage Administrator Access" },
+#ifdef IMPROVED_MODFP_COMPAT
+        { "FrontPageDisable", cmd_disable,
+                NULL, RSRC_CONF, NO_ARGS,
+                "Disable FrontPage" },
+        { "FrontPageEnable", cmd_enable,
+                NULL, RSRC_CONF, NO_ARGS,
+                "Enable FrontPage" },
+        { "FrontPageAdminDisable", cmd_admin_disable,
+                NULL, RSRC_CONF, NO_ARGS,
+                "Disable FrontPageAdmin" },
+        { "FrontPageAdminEnable", cmd_admin_enable,
+                NULL, RSRC_CONF, NO_ARGS,
+                "Enable FrontPageAdmin" },
+#endif
+        { NULL }
+};
 
 /*
  * Declare ourselves so the configuration routines can find us.
@@ -926,9 +1089,9 @@
     FrontPageInit,             /* initializer */
     NULL,                      /* per-directory config creater */
     NULL,                      /* dir config merger - default is to override */
-    NULL,                      /* server config creator */
-    NULL,                      /* server config merger */
-    NULL,                      /* command table */
+    FrontPageCreate_config,    /* server config creator */
+    FrontPageMerge_config,     /* server config merger */
+    FrontPageCMDs,             /* command table */
     NULL,                      /* [6] list of handlers */
     FrontPageXlate,            /* [1] URI-to-filename translation */
     NULL,                      /* [4] check/validate HTTP user_id */
@@ -937,5 +1100,16 @@
     NULL,                      /* [6] MIME type checker/setter */
     FrontPageFixup,                      /* [7] fixups */
     NULL,                      /* [9] logger */
+#if MODULE_MAGIC_NUMBER >= 19970103
     NULL,                      /* [2] header parser */
+#endif
+#if MODULE_MAGIC_NUMBER >= 19970719
+    NULL,                   /* child_init */
+#endif
+#if MODULE_MAGIC_NUMBER >= 19970728
+    NULL,                   /* child_exit */
+#endif
+#if MODULE_MAGIC_NUMBER >= 19970902
+    NULL                    /* post read-request */
+#endif
 };
