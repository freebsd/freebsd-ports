--- src/sslengines/hw_opensc.c.orig	Wed Dec 10 12:21:02 2003
+++ src/sslengines/hw_opensc.c	Wed Dec 10 12:21:21 2003
@@ -62,6 +62,7 @@
 #ifdef HAVE_CONFIG_H
 #include <config.h>
 #endif
+#include <sys/types.h>
 #include <stdio.h>
 #include <string.h>
 #include <openssl/engine.h>
