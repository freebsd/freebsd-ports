Index: plugins/ntlm.c
diff -u -p plugins/ntlm.c.orig plugins/ntlm.c
--- plugins/ntlm.c.orig	Sat Dec 25 01:06:14 2004
+++ plugins/ntlm.c	Wed Sep 28 05:07:18 2005
@@ -74,6 +74,7 @@
 #endif /* WIN32 */
 
 #include <openssl/md4.h>
+#include <openssl/md5.h>
 #include <openssl/hmac.h>
 #include <openssl/des.h>
 #include <openssl/opensslv.h>
