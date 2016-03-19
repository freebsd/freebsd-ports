--- src/mod/endpoints/mod_verto/ws.h.orig	2016-01-12 16:32:36 UTC
+++ src/mod/endpoints/mod_verto/ws.h
@@ -25,7 +25,7 @@
 //#include "sha1.h"
 #include <openssl/ssl.h>
 
-#if defined(_MSC_VER) || defined(__APPLE__) 
+#if defined(_MSC_VER) || defined(__APPLE__) || defined(__FreeBSD__)
 #define __bswap_64(x) \
   x = (x>>56) | \
     ((x<<40) & 0x00FF000000000000) | \
