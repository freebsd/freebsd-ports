
$FreeBSD$

--- src/wyvern.h.orig
+++ src/wyvern.h
@@ -56,6 +56,7 @@
 #include <netdb.h>
 #if	USE_SSL
 #include <openssl/ssl.h>
+#include <openssl/md5.h>
 #endif	/* USE_SSL */
 #include <sys/time.h>
 #include "status.h"
