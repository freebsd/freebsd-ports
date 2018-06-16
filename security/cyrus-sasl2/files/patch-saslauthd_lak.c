--- saslauthd/lak.c.orig	2012-10-12 14:05:48 UTC
+++ saslauthd/lak.c
@@ -53,6 +53,9 @@
 #endif
 #include <openssl/evp.h>
 #include <openssl/des.h>
+
+/* for legacy libcrypto support */
+#include "crypto-compat.h"
 #endif
 
 #define LDAP_DEPRECATED 1
