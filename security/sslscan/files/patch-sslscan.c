--- sslscan.c.orig	2018-06-15 17:47:17 UTC
+++ sslscan.c
@@ -112,6 +112,7 @@
 
 #if defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #endif
 
 #include "sslscan.h"
@@ -896,7 +897,7 @@ int testCompression(struct sslCheckOptions *options, c
 #endif
                         {
                             printf("%sOpenSSL version does not support compression%s\n", COL_RED, RESET);
-                            printf("%sRebuild with zlib1g-dev package for zlib support%s\n\n", COL_RED, RESET);
+                            printf("\n");
                         }
 
                         // Disconnect SSL over socket
