Fix prototype for DH_get0_key() in kexgssgex_client().

--- kexgssc.c.orig	2020-11-24 12:26:37.222092000 -0800
+++ kexgssc.c	2020-11-24 12:26:54.801490000 -0800
@@ -31,6 +31,9 @@
 #include <openssl/crypto.h>
 #include <openssl/bn.h>
 
+#include <openssl/dh.h>
+#include "openbsd-compat/openssl-compat.h"
+
 #include <string.h>
 
 #include "xmalloc.h"
