
$FreeBSD$

--- src/imapcommon.c.orig
+++ src/imapcommon.c
@@ -121,6 +121,7 @@
 #include <errno.h>
 
 #include <openssl/evp.h>
+#include <openssl/md5.h>
 
 #include <pthread.h>
 #include <sys/types.h>
