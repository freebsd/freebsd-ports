--- srs2.c.orig	2015-12-13 08:56:05 UTC
+++ srs2.c
@@ -21,7 +21,11 @@
 #include <sys/types.h>  /* tyepdefs */
 #include <sys/time.h>   /* timeval / timezone struct */
 #include <string.h>		/* memcpy, strcpy, memset */
-#include <alloca.h>
+#if defined(__FreeBSD__)
+#  include <stdlib.h>
+#else
+#  include <alloca.h>
+#endif
 
 #ifdef USE_OPENSSL
 #include <openssl/hmac.h>
