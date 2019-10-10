--- libntech/libutils/hash.h.orig	2019-10-10 06:58:41.000000000 -0700
+++ libntech/libutils/hash.h	2019-10-10 13:03:53.357194000 -0700
@@ -33,6 +33,7 @@
 #include <openssl/evp.h>
 
 #include <hash_method.h>                            /* HashMethod, HashSize */
+#include <bool.h>
 
 
 typedef struct Hash Hash;
