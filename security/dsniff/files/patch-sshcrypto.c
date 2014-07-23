--- ./sshcrypto.c.orig	2001-03-15 09:33:04.000000000 +0100
+++ ./sshcrypto.c	2014-07-22 13:20:14.000000000 +0200
@@ -14,6 +14,9 @@
 
 #include <sys/types.h>
 #include <openssl/ssl.h>
+#include <openssl/blowfish.h>
+#include <openssl/des.h>
+#include <openssl/des_old.h>
 
 #include <err.h>
 #include <stdio.h>
