--- frontpage/version5.0/apache2/mod_frontpage.c.orig	Thu Jan  9 12:19:30 2003
+++ frontpage/version5.0/apache2/mod_frontpage.c	Wed Feb 12 11:29:29 2003
@@ -578,6 +578,32 @@
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
 
@@ -836,6 +862,27 @@
 
 
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
@@ -847,6 +894,7 @@
 {
     char* szVti;
     char* szCgi;
+    cgid_server_conf *c;
 
     /*
      * Decline if we're improperly initialized.
@@ -855,6 +903,13 @@
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
@@ -875,7 +930,7 @@
         return FrontPageAlias(r, szCgi, AUTHOR);
     /*
      * Convert inadvertent shtml.dll to shtml.exe
-     * Thanks for the idea to Scot Hetzel (hetzels@westbend.net)
+     * Thanks for the idea from Scot Hetzel (hetzels@westbend.net)
      */
     if ((szCgi = strstr(szVti, SHTML2 )))
     {
@@ -885,9 +940,17 @@
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
 
