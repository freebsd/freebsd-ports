
$FreeBSD$

--- crypto/ssh_crypto_openssl.c	2001/04/18 16:00:03	1.1
+++ crypto/ssh_crypto_openssl.c	2001/04/18 16:00:24
@@ -44,6 +44,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <string.h>
+#include <sys/types.h>
 
 #include <openssl/rand.h>
 
