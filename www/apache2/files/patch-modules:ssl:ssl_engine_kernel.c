===================================================================
RCS file: /home/cvspublic/modules/ssl/ssl_engine_kernel.c,v
retrieving revision 1.105
retrieving revision 1.106
diff -u -r1.105 -r1.106
--- modules/ssl/ssl_engine_kernel.c	2004/03/05 02:44:40	1.105
+++ modules/ssl/ssl_engine_kernel.c	2004/05/25 12:09:01	1.106
@@ -807,7 +807,6 @@
     SSLConnRec *sslconn = myConnConfig(r->connection);
     SSLSrvConfigRec *sc = mySrvConfig(r->server);
     SSLDirConfigRec *dc = myDirConfig(r);
-    char buf1[MAX_STRING_LEN], buf2[MAX_STRING_LEN];
     char *clientdn;
     const char *auth_line, *username, *password;
 
@@ -886,14 +885,16 @@
      * adding the string "xxj31ZMTZzkVA" as the password in the user file.
      * This is just the crypted variant of the word "password" ;-)
      */
-    apr_snprintf(buf1, sizeof(buf1), "%s:password", clientdn);
-    ssl_util_uuencode(buf2, buf1, FALSE);
-
-    apr_snprintf(buf1, sizeof(buf1), "Basic %s", buf2);
-    apr_table_set(r->headers_in, "Authorization", buf1);
+    auth_line = apr_pstrcat(r->pool, "Basic ", 
+                            ap_pbase64encode(r->pool, 
+                                             apr_pstrcat(r->pool, clientdn, 
+                                                         ":password", NULL)),
+                            NULL);
+    apr_table_set(r->headers_in, "Authorization", auth_line);
 
     ap_log_error(APLOG_MARK, APLOG_INFO, 0, r->server,
-                 "Faking HTTP Basic Auth header: \"Authorization: %s\"", buf1);
+                 "Faking HTTP Basic Auth header: \"Authorization: %s\"",
+                 auth_line);
 
     return DECLINED;
 }

