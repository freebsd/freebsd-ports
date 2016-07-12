--- include/mbedtls/ssl.h.orig	2016-06-27 18:50:36 UTC
+++ include/mbedtls/ssl.h
@@ -52,7 +52,7 @@
 #endif
 
 #if defined(MBEDTLS_HAVE_TIME)
-#include <time.h>
+#include "platform.h"
 #endif
 
 /*
