Fix prototype for DH_get0_key() in kexgssgex_server().

--- kexgsss.c.orig	2020-11-24 12:39:25.548427000 -0800
+++ kexgsss.c	2020-11-24 12:39:47.591119000 -0800
@@ -31,6 +31,9 @@
 #include <openssl/crypto.h>
 #include <openssl/bn.h>
 
+#include <openssl/dh.h>
+#include "openbsd-compat/openssl-compat.h"
+
 #include "xmalloc.h"
 #include "sshbuf.h"
 #include "ssh2.h"
