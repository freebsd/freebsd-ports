--- src/cgi_ssl.c.orig	Thu Nov 20 01:00:59 2003
+++ src/cgi_ssl.c	Thu Nov 20 01:01:17 2003
@@ -19,7 +19,7 @@
  */
 
 #include "boa.h"
-#include <gnutls/x509.h>
+#include <gnutls/gnutls.h>
 
 #ifdef ENABLE_SSL
 extern int ssl_verify;
@@ -44,7 +44,7 @@
 # define GNUTLS_MAX_SESSION_ID 32
 #endif
    char session_id[GNUTLS_MAX_SESSION_ID];
-   int session_id_length = sizeof(session_id);
+   size_t session_id_length = sizeof(session_id);
    int i, ret;
    char str_session_id[(GNUTLS_MAX_SESSION_ID * 2) + 1];
    size_t size;
@@ -128,10 +128,10 @@
    }
 
    {
-      const gnutls_datum *cert_list;
+      const gnutls_datum_t *cert_list;
       char buf[512];
       int cert_list_size, ret;
-      gnutls_x509_crt crt;
+      gnutls_x509_crt_t crt;
 
       buf[0] = 0;
 
