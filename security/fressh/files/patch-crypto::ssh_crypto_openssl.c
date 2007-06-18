
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
 
@@ -183,7 +183,7 @@
 	new_bn = BN_bin2bn(data, bytes, &((*num)->num));
 	if (new_bn == NULL)
 		return (-1);
-	(BIGNUM *) * num = new_bn;
+	*num = (BIGNUM *) new_bn;
 	return (0);
 }
 
