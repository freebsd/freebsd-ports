--- src/modules/module-raop-sink.c.orig	2021-12-16 08:17:48 UTC
+++ src/modules/module-raop-sink.c
@@ -35,6 +35,7 @@
 #include <limits.h>
 #include <math.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 
 #include <openssl/err.h>
 #include <openssl/rand.h>
