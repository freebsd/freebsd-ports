--- sslscan.c.orig	2016-11-06 13:27:11 UTC
+++ sslscan.c
@@ -829,7 +829,7 @@ int testCompression(struct sslCheckOptio
 #endif
                         {
                             printf("%sOpenSSL version does not support compression%s\n", COL_RED, RESET);
-                            printf("%sRebuild with zlib1g-dev package for zlib support%s\n\n", COL_RED, RESET);
+                            printf("\n");
                         }
 
                         // Disconnect SSL over socket
