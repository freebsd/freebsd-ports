--- daemons/ipa-otpd/passkey.c.orig	2026-07-01 20:11:02 UTC
+++ daemons/ipa-otpd/passkey.c
@@ -27,6 +27,7 @@
 #define _GNU_SOURCE /* for asprintf() */
 #include <stdio.h>
 #include <fcntl.h>
+#include <sys/wait.h>
 #include <jansson.h>
 #include <openssl/rand.h>
 #include <openssl/evp.h>
