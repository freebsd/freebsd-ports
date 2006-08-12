
$FreeBSD$

--- lib/fingerprint.c.orig
+++ lib/fingerprint.c
@@ -9,6 +9,7 @@
 #include <fingerprint.h>
 #include <openssl/bio.h>
 #include <openssl/evp.h>
+#include <openssl/md5.h>
 #include <init.h>
 #include <string.h>
 
