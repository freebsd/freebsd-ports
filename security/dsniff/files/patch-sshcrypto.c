--- ./sshcrypto.c.orig	Tue Nov 28 18:23:28 2000
+++ ./sshcrypto.c	Fri Feb  9 01:15:08 2007
@@ -14,6 +14,9 @@
 
 #include <sys/types.h>
 #include <openssl/ssl.h>
+#include <openssl/blowfish.h>
+#include <openssl/des.h>
+#include <openssl/des_old.h>
 
 #include <err.h>
 #include <stdio.h>
