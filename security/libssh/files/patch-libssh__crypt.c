--- ./libssh/crypt.c.orig	2009-05-21 18:46:17.000000000 +1000
+++ ./libssh/crypt.c	2009-07-09 08:21:13.000000000 +1000
@@ -26,6 +26,10 @@
 #include <stdio.h>
 #include <string.h>
 
+#ifndef _WIN32
+#include <arpa/inet.h>
+#endif
+
 #ifdef OPENSSL_CRYPTO
 #include <openssl/blowfish.h>
 #include <openssl/evp.h>
