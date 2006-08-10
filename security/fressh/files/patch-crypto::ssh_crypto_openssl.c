
$FreeBSD$

--- crypto/ssh_crypto_openssl.c.orig
+++ crypto/ssh_crypto_openssl.c
@@ -44,8 +44,10 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <string.h>
+#include <sys/types.h>
 
 #include <openssl/rand.h>
+#include <openssl/sha.h>
 
 #include <openssl/opensslv.h>
 
