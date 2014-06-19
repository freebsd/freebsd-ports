# Latest revision in mod_auth_kerb repo is r157 from from 2009-08-11
# Rev in latest src archive is r150.
# http://modauthkerb.cvs.sourceforge.net/viewvc/modauthkerb/mod_auth_kerb/src/mod_auth_kerb.c?revision=1.157
# Further patched to work with Apache 2.4.
--- src/mod_auth_kerb.c.orig	2008-12-04 11:14:03.000000000 +0100
+++ src/mod_auth_kerb.c	2014-06-01 14:51:14.681087749 +0200
@@ -11,6 +11,12 @@
  */
 
 /*
+ * This file reflects r157 which is not released but contains some fixes
+ * http://modauthkerb.cvs.sourceforge.net/viewvc/modauthkerb/mod_auth_kerb/src/mod_auth_kerb.c?revision=1.157
+ *
+ */
+
+/*
  * Copyright (c) 2004-2006 Masarykova universita
  * (Masaryk University, Brno, Czech Republic)
  * All rights reserved.
@@ -42,7 +48,7 @@
  * POSSIBILITY OF SUCH DAMAGE.
  */
 
-#ident "$Id: mod_auth_kerb.c,v 1.150 2008/12/04 10:14:03 baalberith Exp $"
+#ident "$Id: mod_auth_kerb.c,v 1.157 2009/08/11 07:37:27 kouril Exp $"
 
 #include "config.h"
 
@@ -80,6 +86,12 @@
 #define apr_pool_cleanup_register	ap_register_cleanup
 #endif /* STANDARD20_MODULE_STUFF */
 
+#include <ap_provider.h>
+#include <mod_auth.h>
+#if AP_SERVER_MINORVERSION_NUMBER < 4
+#  define useragent_ip connection->remote_ip
+#endif
+
 #ifdef _WIN32
 #define vsnprintf _vsnprintf
 #define snprintf _snprintf
@@ -88,7 +100,8 @@
 #ifdef KRB5
 #include <krb5.h>
 #ifdef HEIMDAL
-#  include <gssapi.h>
+#  include <gssapi/gssapi.h>
+#  include <gssapi/gssapi_krb5.h>
 #else
 #  include <gssapi/gssapi.h>
 #  include <gssapi/gssapi_generic.h>
@@ -125,7 +138,9 @@
 #  endif
 #endif
 
-#ifdef STANDARD20_MODULE_STUFF
+#if defined(APLOG_USE_MODULE)
+APLOG_USE_MODULE(auth_kerb);
+#elif defined(STANDARD20_MODULE_STUFF)
 module AP_MODULE_DECLARE_DATA auth_kerb_module;
 #else
 module auth_kerb_module;
@@ -298,7 +313,7 @@
 }
 
 /* And this is the operations vector for our replay cache */
-const krb5_rc_ops_internal mod_auth_kerb_rc_ops = {
+static const krb5_rc_ops_internal mod_auth_kerb_rc_ops = {
   0,
   "dfl",
   krb5_rc_dfl_init,
@@ -329,7 +344,7 @@
 	((kerb_auth_config *)rec)->krb_ssl_preauthentication = 0;
 #endif
 #ifdef KRB5
-  ((kerb_auth_config *)rec)->krb5_do_auth_to_local = 0;
+        ((kerb_auth_config *)rec)->krb5_do_auth_to_local = 0;
 	((kerb_auth_config *)rec)->krb_method_k5pass = 1;
 	((kerb_auth_config *)rec)->krb_method_gssapi = 1;
 #endif
@@ -347,9 +362,15 @@
    return NULL;
 }
 
+#ifdef APLOG_USE_MODULE
+static void
+log_rerror(const char *file, int line, int module_index, int level, int status,
+           const request_rec *r, const char *fmt, ...)
+#else
 static void
 log_rerror(const char *file, int line, int level, int status,
            const request_rec *r, const char *fmt, ...)
+#endif
 {
    char errstr[1024];
    va_list ap;
@@ -359,7 +380,9 @@
    va_end(ap);
 
    
-#ifdef STANDARD20_MODULE_STUFF
+#ifdef APLOG_USE_MODULE
+   ap_log_rerror(file, line, module_index, level, status, r, "%s", errstr);
+#elif defined(STANDARD20_MODULE_STUFF)
    ap_log_rerror(file, line, level | APLOG_NOERRNO, status, r, "%s", errstr);
 #else
    ap_log_rerror(file, line, level | APLOG_NOERRNO, r, "%s", errstr);
@@ -527,7 +550,7 @@
    user = apr_pstrcat(r->pool, user, "@", realm, NULL);
 
    MK_USER = user;
-   MK_AUTH_TYPE = "Basic";
+   MK_AUTH_TYPE = "Kerberos";
    apr_table_setn(r->subprocess_env, "KRBTKFILE", tkt_file_p);
 
    if (!conf->krb_save_credentials)
@@ -677,7 +700,8 @@
 static krb5_error_code
 verify_krb5_user(request_rec *r, krb5_context context, krb5_principal principal,
       		 const char *password, krb5_principal server,
-		 krb5_keytab keytab, int krb_verify_kdc, char *krb_service_name, krb5_ccache *ccache)
+		 krb5_keytab keytab, int krb_verify_kdc,
+		 const char *krb_service_name, krb5_ccache *ccache)
 {
    krb5_creds creds;
    krb5_get_init_creds_opt options;
@@ -926,7 +950,6 @@
    return OK;
 }
 
-
 static int
 authenticate_user_krb5pwd(request_rec *r,
                           kerb_auth_config *conf,
@@ -1061,7 +1084,7 @@
       goto end;
    }
    MK_USER = apr_pstrdup (r->pool, name);
-   MK_AUTH_TYPE = "Basic";
+   MK_AUTH_TYPE = "Kerberos";
    free(name);
 
    if (conf->krb_save_credentials)
@@ -1280,6 +1303,7 @@
    return 0;
 }
 
+#ifndef GSSAPI_SUPPORTS_SPNEGO
 static int
 cmp_gss_type(gss_buffer_t token, gss_OID oid)
 {
@@ -1306,6 +1330,7 @@
 
    return memcmp(p, oid->elements, oid->length);
 }
+#endif
 
 static int
 authenticate_user_gss(request_rec *r, kerb_auth_config *conf,
@@ -1438,15 +1463,15 @@
      goto end;
   }
 
-#if 0
-  /* This is a _Kerberos_ module so multiple authentication rounds aren't
-   * supported. If we wanted a generic GSS authentication we would have to do
-   * some magic with exporting context etc. */
+  /* Multiple authentication rounds aren't supported.  If we wanted a generic
+   * GSS authentication we would have to do some magic with exporting context
+   * etc. */
   if (major_status & GSS_S_CONTINUE_NEEDED) {
+     log_rerror(APLOG_MARK, APLOG_ERR, 0, r,
+                "Multi-iteration authentication isn't supported");
      ret = HTTP_UNAUTHORIZED;
      goto end;
   }
-#endif
 
   major_status = gss_display_name(&minor_status, client_name, &output_token, NULL);
   gss_release_name(&minor_status, &client_name); 
@@ -1549,13 +1574,13 @@
 #endif /* KRB5 */
 
 static krb5_conn_data *
-already_succeeded(request_rec *r, char *auth_line)
+already_authorized(request_rec *r, char *auth_line)
 {
    krb5_conn_data *conn_data;
    char keyname[1024];
-
+   
    snprintf(keyname, sizeof(keyname) - 1,
-	"mod_auth_kerb::connection::%s::%ld", r->connection->remote_ip, 
+	"mod_auth_kerb::connection::%s::%ld", r->useragent_ip, 
 	r->connection->id);
 
    if (apr_pool_userdata_get((void**)&conn_data, keyname, r->connection->pool) != 0)
@@ -1571,6 +1596,24 @@
 }
 
 static void
+save_authorized(request_rec *r, char *auth_line, const char *auth_type, int ret) {
+    krb5_conn_data *prevauth;
+    prevauth = (krb5_conn_data *)apr_palloc(r->connection->pool, sizeof(krb5_conn_data));
+    
+    char keyname[1024];
+    
+    prevauth->user = apr_pstrdup(r->connection->pool, MK_USER);
+    prevauth->authline = apr_pstrdup(r->connection->pool, auth_line);
+    prevauth->mech = apr_pstrdup(r->connection->pool, auth_type);
+    prevauth->last_return = ret;
+    
+    snprintf(keyname, sizeof(keyname) - 1,
+             "mod_auth_kerb::connection::%s::%ld",
+             r->useragent_ip, r->connection->id);
+    apr_pool_userdata_set(prevauth, keyname, NULL, r->connection->pool);
+}
+
+static void
 set_kerb_auth_headers(request_rec *r, const kerb_auth_config *conf,
       		      int use_krb4, int use_krb5pwd, char *negotiate_ret_value)
 {
@@ -1607,51 +1650,16 @@
 }
 
 static int
-kerb_authenticate_user(request_rec *r)
+authenticate_user(request_rec *r, char *auth_line, const char *type, int use_krb4, int use_krb5)
 {
-   kerb_auth_config *conf = 
-      (kerb_auth_config *) ap_get_module_config(r->per_dir_config,
-						&auth_kerb_module);
-   krb5_conn_data *prevauth = NULL;
-   const char *auth_type = NULL;
-   char *auth_line = NULL;
-   const char *type = NULL;
-   int use_krb5 = 0, use_krb4 = 0;
    int ret;
-   static int last_return = HTTP_UNAUTHORIZED;
+   krb5_conn_data *prevauth = NULL;
+   kerb_auth_config *conf =
+      (kerb_auth_config *) ap_get_module_config(r->per_dir_config,
+                                                &auth_kerb_module);
    char *negotiate_ret_value = NULL;
-   char keyname[1024];
-
-   /* get the type specified in .htaccess */
-   type = ap_auth_type(r);
-
-   log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r,
-	      "kerb_authenticate_user entered with user %s and auth_type %s",
-	      (MK_USER)?MK_USER:"(NULL)",type?type:"(NULL)");
-
-   if (type && strcasecmp(type, "Kerberos") == 0)
-      use_krb5 = use_krb4 = 1;
-   else if(type && strcasecmp(type, "KerberosV5") == 0)
-      use_krb5 = 1;
-   else if(type && strcasecmp(type, "KerberosV4") == 0)
-      use_krb4 = 1;
-   else
-      return DECLINED;
-
-#if 0
-   if (conf->krb_ssl_preauthentication) {
-      const char *ssl_client_verify = ssl_var_lookup(r->pool, r->server,
-	    	r->connection, r, "SSL_CLIENT_VERIFY");
-
-      if (ssl_client_verify && strcmp(ssl_client_verify, "SUCCESS") == 0)
-	 return OK;
-   }
-#endif
-
-   /* get what the user sent us in the HTTP header */
-   auth_line = (char *)MK_TABLE_GET(r->headers_in, (r->proxyreq == PROXYREQ_PROXY)
-	                                    ? "Proxy-Authorization"
-					    : "Authorization");
+   const char *auth_type = NULL;
+   
    if (!auth_line) {
       set_kerb_auth_headers(r, conf, use_krb4, use_krb5, 
 	                    (use_krb5) ? "\0" : NULL);
@@ -1669,60 +1677,108 @@
 #endif
        (strcasecmp(auth_type, "Basic") == 0))
        return DECLINED;
-
-   if ( (prevauth = already_succeeded(r, auth_line)) == NULL) {
-     ret = HTTP_UNAUTHORIZED;
+   if ((prevauth = already_authorized(r, auth_line)) == NULL) {
+      ret = HTTP_UNAUTHORIZED;
 
 #ifdef KRB5
    if (use_krb5 && conf->krb_method_gssapi &&
        strcasecmp(auth_type, MECH_NEGOTIATE) == 0) {
       ret = authenticate_user_gss(r, conf, auth_line, &negotiate_ret_value);
-   } else if (use_krb5 && conf->krb_method_k5pass &&
-	      strcasecmp(auth_type, "Basic") == 0) {
+   } else if (use_krb5 && (conf->krb_method_k5pass || strcasecmp(type, "Basic"))){
        ret = authenticate_user_krb5pwd(r, conf, auth_line);
    }
 #endif
 
 #ifdef KRB4
-   if (ret == HTTP_UNAUTHORIZED && use_krb4 && conf->krb_method_k4pass &&
-       strcasecmp(auth_type, "Basic") == 0)
+   if (ret == HTTP_UNAUTHORIZED && use_krb4 && (conf->krb_method_k4pass || strcasecmp(type, "Basic")))
       ret = authenticate_user_krb4pwd(r, conf, auth_line);
 #endif
 
-   if (ret == HTTP_UNAUTHORIZED)
-      set_kerb_auth_headers(r, conf, use_krb4, use_krb5, negotiate_ret_value);
+      if (ret == HTTP_UNAUTHORIZED)
+        set_kerb_auth_headers(r, conf, use_krb4, use_krb5, negotiate_ret_value);
 
    } else {
-	ret = prevauth->last_return;
-	MK_USER = prevauth->user;
-	MK_AUTH_TYPE = prevauth->mech;
+      ret = prevauth->last_return;
+      MK_USER = prevauth->user;
+      MK_AUTH_TYPE = prevauth->mech;
    }
 
    /*
     * save who was auth'd, if it's not already stashed.
     */
-     if(!prevauth) {
-       prevauth = (krb5_conn_data *) apr_pcalloc(r->connection->pool, sizeof(krb5_conn_data));
-       prevauth->user = apr_pstrdup(r->connection->pool, MK_USER);
-       prevauth->authline = apr_pstrdup(r->connection->pool, auth_line);
-       prevauth->mech = apr_pstrdup(r->connection->pool, auth_type);
-       prevauth->last_return = ret;
-       snprintf(keyname, sizeof(keyname) - 1,
-           "mod_auth_kerb::connection::%s::%ld", 
-	   r->connection->remote_ip, r->connection->id);
-       apr_pool_userdata_set(prevauth, keyname, NULL, r->connection->pool);
+   if(!prevauth) {
+      save_authorized(r, auth_line, auth_type, ret);
+   }
+
+   if (ret == OK && conf->krb5_do_auth_to_local) {
+      ret = do_krb5_an_to_ln(r);
    }
+   return ret;
+}
 
-     if (ret == OK && conf->krb5_do_auth_to_local)
-       ret = do_krb5_an_to_ln(r);
+static authn_status authn_krb_password(request_rec *r, const char *user,
+                                       const char *password)
+{
+   char *auth_line = NULL;
+   int ret;
+   const char *type = NULL;
+   
+   type = ap_auth_type(r);
+   auth_line = ap_pbase64encode (r->pool, apr_psprintf(r->pool, "%s:%s", user, password));
+   auth_line = apr_psprintf(r->pool, "Basic %s", auth_line);
+
+   ret = authenticate_user(r, auth_line, type, 1, 1);
    
-   /* XXX log_debug: if ret==OK, log(user XY authenticated) */
+   if (ret == OK) return AUTH_GRANTED;
+   else return AUTH_USER_NOT_FOUND;
+}
+
+static int
+kerb_authenticate_user(request_rec *r)
+{
+   kerb_auth_config *conf = 
+      (kerb_auth_config *) ap_get_module_config(r->per_dir_config,
+						&auth_kerb_module);
+   char *auth_line = NULL;
+   int ret, use_krb4 = 0, use_krb5 = 0;
+   const char *type = NULL;
+   
+   /* get the type specified in .htaccess */
+   type = ap_auth_type(r);
+
+   log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r,
+	      "kerb_authenticate_user entered with user %s and auth_type %s",
+	      (MK_USER)?MK_USER:"(NULL)",type?type:"(NULL)");
+
+   if (type && strcasecmp(type, "Kerberos") == 0)
+      use_krb5 = use_krb4 = 1;
+   else if(type && strcasecmp(type, "KerberosV5") == 0)
+      use_krb5 = 1;
+   else if(type && strcasecmp(type, "KerberosV4") == 0)
+      use_krb4 = 1;
+   else
+      return DECLINED;
+
+#if 0
+   if (conf->krb_ssl_preauthentication) {
+      const char *ssl_client_verify = ssl_var_lookup(r->pool, r->server,
+	    	r->connection, r, "SSL_CLIENT_VERIFY");
+
+      if (ssl_client_verify && strcmp(ssl_client_verify, "SUCCESS") == 0)
+	 return OK;
+   }
+#endif
+
+   /* get what the user sent us in the HTTP header */
+   auth_line = (char *)MK_TABLE_GET(r->headers_in, (r->proxyreq == PROXYREQ_PROXY)
+	                                    ? "Proxy-Authorization"
+					    : "Authorization");
+   ret = authenticate_user(r, auth_line, type, use_krb4, use_krb5);
 
-   last_return = ret;
    return ret;
 }
 
-int
+static int
 have_rcache_type(const char *type)
 {
    krb5_error_code ret;
@@ -1805,6 +1861,12 @@
 static void
 kerb_register_hooks(apr_pool_t *p)
 {
+   static const authn_provider authn_krb_provider = {
+      &authn_krb_password,
+      NULL
+   };
+
+   ap_register_provider(p, AUTHN_PROVIDER_GROUP, "kerberos", "0", &authn_krb_provider);
    ap_hook_post_config(kerb_init_handler, NULL, NULL, APR_HOOK_MIDDLE);
    ap_hook_check_user_id(kerb_authenticate_user, NULL, NULL, APR_HOOK_MIDDLE);
 }
