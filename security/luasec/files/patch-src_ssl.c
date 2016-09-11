--- src/ssl.c.orig	2015-11-20 21:39:32 UTC
+++ src/ssl.c
@@ -15,6 +15,7 @@
 #endif
 
 #include <openssl/ssl.h>
+#include <openssl/comp.h>
 #include <openssl/x509v3.h>
 #include <openssl/x509_vfy.h>
 #include <openssl/err.h>
