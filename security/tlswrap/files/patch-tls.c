--- tls.c.orig	2015-02-27 22:39:36.433393086 +0100
+++ tls.c	2015-02-27 22:40:53.392227938 +0100
@@ -72,14 +72,8 @@
 	if (debug)
 		printf("egd_sock is %s\n", egd_sock);
 #ifdef HAVE_RAND_STATUS
-	if (RAND_status() != 1) {
-		if ( RAND_egd(egd_sock) == -1 ) {
-			fprintf(stderr, "egd_sock is %s\n", egd_sock);
-			sys_err("RAND_egd failed\n");
-		}
-		if (RAND_status() != 1)
-			sys_err("ssl_init: System without /dev/urandom, PRNG seeding must be done manually.\r\n");
-	}
+	if (RAND_status() != 1)
+		sys_err("ssl_init: System without /dev/urandom, PRNG seeding must be done manually.\r\n");
 #endif
 	/*
 	SSL_CTX_set_options(tls_ctx, SSL_OP_ALL | SSL_OP_NO_SSLv2);
