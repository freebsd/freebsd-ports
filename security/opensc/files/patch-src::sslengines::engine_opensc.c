--- src/sslengines/engine_opensc.c.orig	Wed Dec 10 12:20:59 2003
+++ src/sslengines/engine_opensc.c	Wed Dec 10 12:21:11 2003
@@ -27,6 +27,7 @@
 #ifdef HAVE_CONFIG_H
 #include <config.h>
 #endif
+#include <sys/types.h>
 #include <stdio.h>
 #include <string.h>
 #include <openssl/crypto.h>
