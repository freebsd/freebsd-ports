--- frontpage/version5.0/apache2/mod_frontpage.c-orig	Tue Dec  2 20:18:45 2003
+++ frontpage/version5.0/apache2/mod_frontpage.c	Tue Jan 17 18:01:02 2006
@@ -62,7 +62,6 @@
 #include <dirent.h>  
 #include <errno.h>
 #include <unistd.h>
-#include "apr_compat.h" 
 #include "apr_strings.h" 
 #include "http_log.h"
 
@@ -590,6 +589,32 @@
      * Thanks to Scot Hetzel (hetzels@westbend.net)
      */
     ap_add_version_component(p, "FrontPage/5.0.2.2635");
+
+    while (s != NULL) {
+	cgid_server_conf* c = ap_get_module_config(s->module_config, &frontpage_module);
+	if (c->fp_status == -1)
+#ifdef DEFAULT_TO_OFF
+	   c->fp_status = FALSE;
+#else
+	   c->fp_status = TRUE;
+#endif
+	if (!c->fp_status)
+	    ap_log_error(APLOG_MARK, APLOG_DEBUG|APLOG_NOERRNO, 0, s,
+			 "FrontPage disabled for server %s:%d\n",
+			 s->server_hostname, s->port);
+	if (c->fp_admin_status == -1)
+#ifdef DEFAULT_TO_OFF
+	   c->fp_admin_status = FALSE;
+#else
+	   c->fp_admin_status = TRUE;
+#endif
+	if (!c->fp_admin_status)
+	   ap_log_error(APLOG_MARK, APLOG_DEBUG|APLOG_NOERRNO, 0, s,
+			"FrontPage Administration pages disabled for server %s:%d\n",
+			s->server_hostname, s->port);
+	s = s->next;
+    }
+
     return OK;
 }
 
@@ -781,20 +806,20 @@
         return DECLINED;
 
     /*
-     * Note: ap_pstrdup allocates memory, but it checks for out of memory
+     * Note: apr_pstrdup allocates memory, but it checks for out of memory
      * conditions - it will not return if out of memory.
      */
-    r->handler = ap_pstrdup(r->pool, "cgi-script");
-    ap_table_set(r->notes, "alias-forced-type", r->handler);
+    r->handler = apr_pstrdup(r->pool, "cgi-script");
+    apr_table_set(r->notes, "alias-forced-type", r->handler);
 
-    ap_table_set(r->subprocess_env, "FPEXE", ap_pstrdup(r->pool, szFpexe));
+    apr_table_set(r->subprocess_env, "FPEXE", apr_pstrdup(r->pool, szFpexe));
     sprintf(szBuf, "%d", webroot.st_uid );
-    ap_table_set(r->subprocess_env, "FPUID", ap_pstrdup(r->pool, szBuf));
+    apr_table_set(r->subprocess_env, "FPUID", apr_pstrdup(r->pool, szBuf));
     sprintf(szBuf, "%d", webroot.st_gid );
-    ap_table_set(r->subprocess_env, "FPGID", ap_pstrdup(r->pool, szBuf));
+    apr_table_set(r->subprocess_env, "FPGID", apr_pstrdup(r->pool, szBuf));
 
-    ap_table_set(r->notes,"FPexecfilename", ap_pstrcat(r->pool, FPSTUB, NULL));
-    r->filename = ap_pstrcat(r->pool, r->filename, szCgi, NULL);
+    apr_table_set(r->notes,"FPexecfilename", apr_pstrcat(r->pool, FPSTUB, NULL));
+    r->filename = apr_pstrcat(r->pool, r->filename, szCgi, NULL);
 
     return OK;
 }
@@ -836,8 +861,8 @@
         sprintf(szBuf, "/%04d", iLcid);
 
     /* see the note in FrontPageAlias */
-    execFilename =  ap_pstrcat(r->pool, FP, szDir, szBuf, szBase, NULL);
-    ap_table_set(r->notes,"FPexecfilename", execFilename);
+    execFilename =  apr_pstrcat(r->pool, FP, szDir, szBuf, szBase, NULL);
+    apr_table_set(r->notes,"FPexecfilename", execFilename);
     /* We need to set the finfo field now.  Otherwise Apache will set
        the path_info field automatically but incorrectly, which will result 
        in the wrong file being checked.
@@ -849,6 +874,27 @@
 
 
 /*
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
+    if ((r->user == NULL) || (r->ap_auth_type == NULL)) {
+       ap_log_rerror(APLOG_MARK, APLOG_NOERRNO|APLOG_ERR, 0, r,
+            "server configuration did not require authentication: %s", r->filename);
+       return HTTP_UNAUTHORIZED;
+    } else {
+       return FrontPageAlias(r, szCgi, szFpexe);
+    }
+}
+
+/*
  * This routine looks for shtml.exe, fpcount.exe, author.exe and admin.exe
  * in a URI, and if found we call FrontPageAlias() to check for a valid
  * FrontPage scenario.
@@ -860,6 +906,7 @@
 {
     char* szVti;
     char* szCgi;
+    cgid_server_conf *c;
 
     /*
      * Decline if we're improperly initialized.
@@ -868,6 +915,13 @@
         return DECLINED;
 
     /*
+     * Decline if we have disabled FrontPage on the server.
+     */
+    c = (cgid_server_conf *)ap_get_module_config (r->server->module_config, &frontpage_module);
+       if (!c->fp_status)
+           return HTTP_FORBIDDEN;
+
+    /*
      * Check once for anything with _vti_bin.  This is much faster than
      * checking all our paths, because anything without this is definitely
      * not a FrontPage scenario.
@@ -888,7 +942,7 @@
         return FrontPageAlias(r, szCgi, AUTHOR);
     /*
      * Convert inadvertent shtml.dll to shtml.exe
-     * Thanks for the idea to Scot Hetzel (hetzels@westbend.net)
+     * Thanks for the idea from Scot Hetzel (hetzels@westbend.net)
      */
     if ((szCgi = strstr(szVti, SHTML2 )))
     {
@@ -898,9 +952,17 @@
     if ((szCgi = strstr(szVti, SHTML  )))
         return FrontPageAlias(r, szCgi, SHTML);
     if ((szCgi = strstr(szVti, ADMIN  )))
-        return FrontPageAlias(r, szCgi, ADMIN);
+	if (c->fp_admin_status) {
+	    return FrontPageAlias(r, szCgi, ADMIN);
+	} else {
+	    return HTTP_FORBIDDEN;
+	}
     if ((szCgi = strstr(szVti, ADMINCGI  )))
-        return FrontPageAlias(r, szCgi, ADMINCGI);
+	if (c->fp_admin_status) {
+	    return FrontPageAlias(r, szCgi, ADMINCGI);
+	} else {
+	    return HTTP_FORBIDDEN;
+	}
     if ((szCgi = strstr(szVti, FPCOUNT)))
         return FrontPageAlias(r, szCgi, FPCOUNT);
 
@@ -939,13 +1001,13 @@
 static int FrontPageFixup(request_rec *r)
 {
 
-    if (!ap_table_get(r->notes, "FPexecfilename"))
+    if (!apr_table_get(r->notes, "FPexecfilename"))
     {  
         FrontPageXlate(r);
     }
-    if (ap_table_get(r->notes,"FPexecfilename"))
+    if (apr_table_get(r->notes,"FPexecfilename"))
     {
-        r->filename = (char*) ap_table_get(r->notes,"FPexecfilename");
+        r->filename = (char*) apr_table_get(r->notes,"FPexecfilename");
         apr_stat(&r->finfo, r->filename, APR_FINFO_MIN, r->pool);
     }
 
