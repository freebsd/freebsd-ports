--- ../spnego-http-auth-nginx-module-c626163/ngx_http_auth_spnego_module.c.orig	2022-02-19 21:05:54.082252000 +0100
+++ ../spnego-http-auth-nginx-module-c626163/ngx_http_auth_spnego_module.c	2022-02-19 21:12:17.316744000 +0100
@@ -63,6 +63,11 @@
 #define spnego_log_error(fmt, args...)                                         \
     ngx_log_error(NGX_LOG_ERR, r->connection->log, 0, fmt, ##args)
 
+#ifndef krb5_realm_length
+#define krb5_realm_length(r) ((r).length)
+#define krb5_realm_data(r) ((r).data)
+#endif
+
 /* Module handler */
 static ngx_int_t ngx_http_auth_spnego_handler(ngx_http_request_t *);
 
@@ -1195,12 +1200,12 @@ static krb5_error_code ngx_http_auth_spnego_verify_ser
     }
 
     size_t tgs_principal_name_size =
-        (ngx_strlen(KRB5_TGS_NAME) + (principal->realm.length * 2) + 2) + 1;
+        (ngx_strlen(KRB5_TGS_NAME) + (krb5_realm_length(principal->realm) * 2) + 2) + 1;
     tgs_principal_name = (char *)ngx_pcalloc(r->pool, tgs_principal_name_size);
     ngx_snprintf((u_char *)tgs_principal_name, tgs_principal_name_size,
-                 "%s/%*s@%*s", KRB5_TGS_NAME, principal->realm.length,
-                 principal->realm.data, principal->realm.length,
-                 principal->realm.data);
+                 "%s/%*s@%*s", KRB5_TGS_NAME, krb5_realm_length(principal->realm),
+                 krb5_realm_data(principal->realm), krb5_realm_length(principal->realm),
+                 krb5_realm_data(principal->realm));
 
     if ((kerr = krb5_parse_name(kcontext, tgs_principal_name,
                                 &match_creds.server))) {
@@ -1341,13 +1346,13 @@ static ngx_int_t ngx_http_auth_spnego_obtain_server_cr
     krb5_get_init_creds_opt_set_forwardable(&gicopts, 1);
 
     size_t tgs_principal_name_size =
-        (ngx_strlen(KRB5_TGS_NAME) + (principal->realm.length * 2) + 2) + 1;
+        (ngx_strlen(KRB5_TGS_NAME) + (krb5_realm_length(principal->realm) * 2) + 2) + 1;
     tgs_principal_name = (char *)ngx_pcalloc(r->pool, tgs_principal_name_size);
 
     ngx_snprintf((u_char *)tgs_principal_name, tgs_principal_name_size,
-                 "%s/%*s@%*s", KRB5_TGS_NAME, principal->realm.length,
-                 principal->realm.data, principal->realm.length,
-                 principal->realm.data);
+                 "%s/%*s@%*s", KRB5_TGS_NAME, krb5_realm_length(principal->realm),
+                 krb5_realm_data(principal->realm), krb5_realm_length(principal->realm),
+                 krb5_realm_data(principal->realm));
 
     kerr = krb5_get_init_creds_keytab(kcontext, &creds, principal, keytab, 0,
                                       tgs_principal_name, &gicopts);
