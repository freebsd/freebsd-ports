--- src/osdep/unix/ssl_unix.c.orig	2011-07-23 00:20:10 UTC
+++ src/osdep/unix/ssl_unix.c
@@ -270,9 +270,9 @@ static char *ssl_start_work (SSLSTREAM *
       (err = ssl_validate_cert (cert = SSL_get_peer_certificate (stream->con),
 				host))) {
 				/* application callback */
-    if (scq) return (*scq) (err,host,cert ? cert->name : "???") ? NIL : "";
+    if (scq) return (*scq) (err,host,cert ? X509_get_subject_name(cert) : "???") ? NIL : "";
 				/* error message to return via mm_log() */
-    sprintf (tmp,"*%.128s: %.255s",err,cert ? cert->name : "???");
+    sprintf (tmp,"*%.128s: %.255s",err,cert ? X509_get_subject_name(cert) : "???");
     return ssl_last_error = cpystr (tmp);
   }
   return NIL;
@@ -322,9 +322,9 @@ static char *ssl_validate_cert (X509 *ce
 				/* make sure have a certificate */
   if (!cert) ret = "No certificate from server";
 				/* and that it has a name */
-  else if (!cert->name) ret = "No name in certificate";
+  else if (!X509_get_subject_name(cert)) ret = "No name in certificate";
 				/* locate CN */
-  else if (s = strstr (cert->name,"/CN=")) {
+  else if (s = strstr (X509_get_subject_name(cert),"/CN=")) {
     if (t = strchr (s += 4,'/')) *t = '\0';
 				/* host name matches pattern? */
     ret = ssl_compare_hostnames (host,s) ? NIL :
