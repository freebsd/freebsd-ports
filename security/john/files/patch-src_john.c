--- src/john.c.orig	2012-09-20 01:50:17 UTC
+++ src/john.c
@@ -183,7 +183,9 @@ extern struct fmt_main fmt_wpapsk;
 
 extern struct fmt_main fmt_hmacMD5;
 extern struct fmt_main fmt_hmacSHA1;
+#ifndef OPENSSL_NO_SHA0
 extern struct fmt_main fmt_rawSHA0;
+#endif
 
 extern int unique(int argc, char **argv);
 extern int unshadow(int argc, char **argv);
@@ -241,7 +243,9 @@ static void john_register_all(void)
 
 	john_register_one(&fmt_hmacMD5);
 	john_register_one(&fmt_hmacSHA1);
+#ifndef OPENSSL_NO_SHA0
 	john_register_one(&fmt_rawSHA0);
+#endif
 
 #if OPENSSL_VERSION_NUMBER >= 0x00908000
 	john_register_one(&fmt_rawSHA224);
