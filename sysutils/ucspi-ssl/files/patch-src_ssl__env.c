--- src/ssl_env.c.orig	2017-01-25 20:24:35 UTC
+++ src/ssl_env.c
@@ -1,5 +1,6 @@
 #include <unistd.h>
 #include <openssl/x509.h>
+#include <openssl/opensslv.h>
 #include <string.h>
 #include "fmt.h"
 #include "pathexec.h"
@@ -227,7 +228,7 @@ static int ssl_client_vars(X509 *cert,ST
   set_env_id(xname,"SSL_CLIENT_I_DN_Email",NID_pkcs9_emailAddress);
 
 /* Signature Algorithm for PubKey */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   n = OBJ_obj2nid(cert->cert_info->signature->algorithm);
 #else
   sigalg = X509_get0_tbs_sigalg(cert);
@@ -371,7 +372,7 @@ static int ssl_server_vars(X509 *cert,ST
   set_env_id(xname,"SSL_SERVER_I_DN_Email",NID_pkcs9_emailAddress);
 
 /* Signature Algorithm of PubKey */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   n = OBJ_obj2nid(cert->cert_info->signature->algorithm);
 #else
   sigalg = X509_get0_tbs_sigalg(cert);
