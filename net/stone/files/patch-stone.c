--- stone.c.orig	2019-02-15 07:01:05 UTC
+++ stone.c
@@ -9382,7 +9382,7 @@ int sslopts(int argc, int argi, char *argv[], SSLOpts 
 	if (isserver) opts->meth = SSLv3_server_method();
 	else opts->meth = SSLv3_client_method();
 #endif
-#ifndef OPENSSL_NO_SSL2
+#if !defined(OPENSSL_NO_SSL2) && OPENSSL_VERSION_NUMBER < 0x10100000L
     } else if (!strcmp(argv[argi], "ssl2")) {
 	if (isserver) opts->meth = SSLv2_server_method();
 	else opts->meth = SSLv2_client_method();
