--- srs2.c	2014-01-03 01:01:47.000000000 +0100
+++ srs2.c.new	2014-06-17 16:13:45.773381667 +0200
@@ -21,7 +21,7 @@
 #include <sys/types.h>  /* tyepdefs */
 #include <sys/time.h>   /* timeval / timezone struct */
 #include <string.h>		/* memcpy, strcpy, memset */
-#include <alloca.h>
+#include <stdlib.h>
 
 #ifdef USE_OPENSSL
 #include <openssl/hmac.h>
