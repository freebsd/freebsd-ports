--- mod_auth_remote.c.orig	Tue Jan 21 16:44:53 2003
+++ mod_auth_remote.c	Sun Dec  7 22:42:36 2003
@@ -141,8 +141,8 @@
    itemp = strlen(user_pass);
    encoded = apr_palloc(r->pool, (((itemp+2)/3)*4)+2); 
    apr_base64_encode(encoded, user_pass, itemp);
-   req_b = apr_pstrcat(r->pool, "HEAD ", conf->remote_uri," HTTP/1.0 ", 
-                       "\nAuthorization: Basic ",encoded,CRLF,CRLF,NULL);
+   req_b = apr_pstrcat(r->pool, "HEAD ", conf->remote_uri," HTTP/1.0", 
+                       CRLF,"Authorization: Basic ",encoded,CRLF,CRLF,NULL);
    bytes = strlen(req_b);
    val = apr_send(socket, req_b, &bytes);
    if(val != APR_SUCCESS)
@@ -194,4 +194,4 @@
   NULL,
   auth_remote_cmds,
   register_hooks
-};
\ No newline at end of file
+};
