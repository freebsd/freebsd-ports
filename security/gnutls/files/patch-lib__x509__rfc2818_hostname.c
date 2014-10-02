--- lib/x509/rfc2818_hostname.c.orig	2014-10-02 13:35:09.427374817 -0500
+++ lib/x509/rfc2818_hostname.c	2014-10-02 13:35:33.657427866 -0500
@@ -19,6 +19,7 @@
  *
  */
 
+#include <netinet/in.h>
 #include <gnutls_int.h>
 #include <gnutls_str.h>
 #include <x509_int.h>
