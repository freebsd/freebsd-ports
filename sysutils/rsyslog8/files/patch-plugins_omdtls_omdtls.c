--- plugins/omdtls/omdtls.c.orig	2024-02-26 08:24:02 UTC
+++ plugins/omdtls/omdtls.c
@@ -43,6 +43,7 @@
 #endif
 #include <sys/time.h>
 #include <time.h>
+#include <unistd.h>
 
 // --- Include openssl headers as well
 #include <openssl/ssl.h>
