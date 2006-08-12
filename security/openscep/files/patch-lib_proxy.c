
$FreeBSD$

--- lib/proxy.c.orig
+++ lib/proxy.c
@@ -10,6 +10,7 @@
 #include <scep.h>
 #include <proxy.h>
 #include <openssl/evp.h>
+#include <openssl/md5.h>
 
 /*
  * proxy_authenticator	compute the proxy authenticator hash value
