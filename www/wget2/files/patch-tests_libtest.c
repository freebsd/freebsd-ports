--- tests/libtest.c.orig	2025-12-29 13:41:40 UTC
+++ tests/libtest.c
@@ -73,6 +73,8 @@ enum MHD_Result {
 #include <sys/socket.h>
 #include <netdb.h>
 
+#include <netinet/in.h>
+
 #ifdef WITH_GNUTLS_IN_TESTSUITE
 #ifdef WITH_GNUTLS_OCSP
 #  include <gnutls/ocsp.h>
