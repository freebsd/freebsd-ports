--- src/main.c.orig	2002-12-17 19:28:19 UTC
+++ src/main.c
@@ -296,7 +296,7 @@ loopZ (void)
 #if defined(CONFIG_CIPHER)
 #include "cipher.h"
 
-#if USE_OPENSSL
+#if USE_OPENSSL && !defined(OPENSSL_NO_EGD)
 #include <openssl/rand.h>
 
 static char *egd_path = 0;
@@ -324,7 +324,7 @@ set_egd_path (char **egd_pathp, const ch
 static void
 cipher_init (void)
 {
-#if USE_OPENSSL
+#if USE_OPENSSL && !defined(OPENSSL_NO_EGD)
 	variable_add(&egd_path, set_egd_path, "egd_path");
 #else
 	srand(getpid()*clock());
