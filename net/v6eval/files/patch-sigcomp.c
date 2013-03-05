--- bin/sigcomp/sigcomp.c	2005-05-27 20:40:19.000000000 +0900
+++ bin/sigcomp/sigcomp.c	2008-01-01 06:03:23.000000000 +0900
@@ -53,7 +53,7 @@
 
 #include <openssl/err.h>
 #include <openssl/evp.h>
-
+#include <openssl/rsa.h>
 
 
 #ifdef DEBUG
