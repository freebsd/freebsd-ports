--- ../spnego-http-auth-nginx-module-c626163/ngx_http_auth_spnego_module.c.orig
+++ ../spnego-http-auth-nginx-module-c626163/ngx_http_auth_spnego_module.c
@@ -502,6 +502,7 @@ ngx_http_auth_spnego_headers_basic_only(ngx_http_request_t *r,
     }
 
     r->headers_out.www_authenticate->hash = 1;
+    r->headers_out.www_authenticate->next = NULL;
     r->headers_out.www_authenticate->key.len = sizeof("WWW-Authenticate") - 1;
     r->headers_out.www_authenticate->key.data = (u_char *)"WWW-Authenticate";
     r->headers_out.www_authenticate->value.len = value.len;
@@ -538,6 +539,7 @@ ngx_http_auth_spnego_headers(ngx_http_request_t *r,
     }
 
     r->headers_out.www_authenticate->hash = 1;
+    r->headers_out.www_authenticate->next = NULL;
     r->headers_out.www_authenticate->key.len = sizeof("WWW-Authenticate") - 1;
     r->headers_out.www_authenticate->key.data = (u_char *)"WWW-Authenticate";
     r->headers_out.www_authenticate->value.len = value.len;
@@ -559,6 +561,7 @@ ngx_http_auth_spnego_headers(ngx_http_request_t *r,
         }
 
         r->headers_out.www_authenticate->hash = 2;
+        r->headers_out.www_authenticate->next = NULL;
         r->headers_out.www_authenticate->key.len =
             sizeof("WWW-Authenticate") - 1;
         r->headers_out.www_authenticate->key.data =
@@ -758,6 +761,12 @@ ngx_http_auth_spnego_store_delegated_creds(ngx_http_request_t *r,
     char *ccname = NULL;
     char *escaped = NULL;
 
+    if ((kerr = krb5_init_context(&kcontext))) {
+        spnego_log_error("Kerberos error: Cannot initialize kerberos context");
+        spnego_log_krb5_error(kcontext, kerr);
+        goto done;
+    }
+
     if (!delegated_creds.data) {
         spnego_log_error(
             "ngx_http_auth_spnego_store_delegated_creds() NULL credentials");
@@ -766,12 +775,6 @@ ngx_http_auth_spnego_store_delegated_creds(ngx_http_request_t *r,
         goto done;
     }
 
-    if ((kerr = krb5_init_context(&kcontext))) {
-        spnego_log_error("Kerberos error: Cannot initialize kerberos context");
-        spnego_log_krb5_error(kcontext, kerr);
-        goto done;
-    }
-
     if ((kerr = krb5_parse_name(kcontext, (char *)principal_name->data,
                                 &principal))) {
         spnego_log_error("Kerberos error: Cannot parse principal %s",
