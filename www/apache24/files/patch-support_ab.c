$OpenBSD: patch-support_ab_c,v 1.1 2015/07/18 04:59:42 sthen Exp $
--- support/ab.c.orig	Fri Jul 17 22:55:57 2015
+++ support/ab.c	Fri Jul 17 22:56:13 2015
@@ -2314,8 +2314,10 @@ int main(int argc, const char * const argv[])
                 } else if (strncasecmp(opt_arg, "SSL2", 4) == 0) {
                     meth = SSLv2_client_method();
 #endif
+#ifndef OPENSSL_NO_SSL3
                 } else if (strncasecmp(opt_arg, "SSL3", 4) == 0) {
                     meth = SSLv3_client_method();
+#endif
 #ifdef HAVE_TLSV1_X
                 } else if (strncasecmp(opt_arg, "TLS1.1", 6) == 0) {
                     meth = TLSv1_1_client_method();
