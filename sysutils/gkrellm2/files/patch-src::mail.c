Index: src/mail.c
diff -u -p src/mail.c.orig src/mail.c
--- src/mail.c.orig	Wed Aug  9 07:31:30 2006
+++ src/mail.c	Tue Dec 26 11:25:25 2006
@@ -39,6 +39,7 @@
 
 #if defined(HAVE_GNUTLS)
 #include <gnutls/openssl.h>
+#include <gcrypt.h>
 #include <pthread.h>
 #define MD5Init		MD5_Init
 #define MD5Update	MD5_Update
