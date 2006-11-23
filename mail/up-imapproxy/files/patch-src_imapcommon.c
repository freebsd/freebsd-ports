
$FreeBSD$

--- src/imapcommon.c.orig
+++ src/imapcommon.c
@@ -136,6 +136,7 @@
 
 #include <openssl/evp.h>
 #include <openssl/err.h>
+#include <openssl/md5.h>
 
 #include <pthread.h>
 #include <sys/types.h>
