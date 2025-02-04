--- ../nginx-auth-ldap-241200e/ngx_http_auth_ldap_module.c.orig	2022-08-21 17:04:57.754760000 +0300
+++ ../nginx-auth-ldap-241200e/ngx_http_auth_ldap_module.c	2022-08-21 17:08:46.939318000 +0300
@@ -1779,6 +1779,7 @@
     }
 
     r->headers_out.www_authenticate->hash = 1;
+    r->headers_out.www_authenticate->next = NULL;
     r->headers_out.www_authenticate->key.len = sizeof("WWW-Authenticate") - 1;
     r->headers_out.www_authenticate->key.data = (u_char *) "WWW-Authenticate";
     r->headers_out.www_authenticate->value = *realm;
