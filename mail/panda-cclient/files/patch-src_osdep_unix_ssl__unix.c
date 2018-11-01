--- src/osdep/unix/ssl_unix.c.orig	2013-06-21 21:29:17 UTC
+++ src/osdep/unix/ssl_unix.c
@@ -22,6 +22,10 @@
  *     http://www.apache.org/licenses/LICENSE-2.0
  *
  */
+
+/* Patch for OPENSSL_VERSION_NUMBER >= 0x10100000 obtained from
+ * openembedded/meta-openembedded (on GitHub)
+ */
 
 #define crypt ssl_private_crypt
 #define STRING OPENSSL_STRING
@@ -241,8 +245,16 @@ static char *ssl_start_work (SSLSTREAM *
 				/* disable certificate validation? */
   if (flags & NET_NOVALIDATECERT)
     SSL_CTX_set_verify (stream->context,SSL_VERIFY_NONE,NIL);
-  else SSL_CTX_set_verify (stream->context,SSL_VERIFY_PEER,ssl_open_verify);
+  else {
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
+      X509_VERIFY_PARAM *param = SSL_CTX_get0_param(stream->context);
+      X509_VERIFY_PARAM_set_hostflags(param, X509_CHECK_FLAG_NO_PARTIAL_WILDCARDS);
+      X509_VERIFY_PARAM_set1_host(param, host, 0);
+#endif
+
+      SSL_CTX_set_verify (stream->context,SSL_VERIFY_PEER,ssl_open_verify);
 				/* set default paths to CAs... */
+  }
   SSL_CTX_set_default_verify_paths (stream->context);
 				/* ...unless a non-standard path desired */
   if (s = (char *) mail_parameters (NIL,GET_SSLCAPATH,NIL))
@@ -280,6 +292,7 @@ static char *ssl_start_work (SSLSTREAM *
   if (SSL_write (stream->con,"",0) < 0)
     return ssl_last_error ? ssl_last_error : "SSL negotiation failed";
 				/* need to validate host names? */
+#if OPENSSL_VERSION_NUMBER < 0x10100000
   if (!(flags & NET_NOVALIDATECERT) &&
       (err = ssl_validate_cert (cert = SSL_get_peer_certificate (stream->con),
 				host))) {
@@ -289,6 +302,7 @@ static char *ssl_start_work (SSLSTREAM *
     sprintf (tmp,"*%.128s: %.255s",err,cert ? cert->name : "???");
     return ssl_last_error = cpystr (tmp);
   }
+#endif
   return NIL;
 }
 
@@ -327,6 +341,7 @@ static int ssl_open_verify (int ok,X509_
  * Returns: NIL if validated, else string of error message
  */
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000
 static char *ssl_validate_cert (X509 *cert,char *host)
 {
   int i,n;
@@ -356,6 +371,7 @@ static char *ssl_validate_cert (X509 *ce
   else ret = "Unable to locate common name in certificate";
   return ret;
 }
+#endif
 
 /* Case-independent wildcard pattern match
  * Accepts: base string
