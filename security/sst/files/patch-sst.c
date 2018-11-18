--- sst.c	2015-05-06 09:24:06.000000000 -0400
+++ sst.c	2018-11-04 18:57:40.626302000 -0500
@@ -213,5 +213,5 @@
  */
 #ifndef lint
-static char rcsid[] = "$Header: /c/src/local.bin/sst/RCS/sst.c,v 1.23 2015/05/06 13:24:00 pkern Exp $";
+static const char rcsid[] = "$Header: /c/src/local.bin/sst/RCS/sst.c,v 1.23 2015/05/06 13:24:00 pkern Exp $";
 #endif
 
@@ -267,8 +267,8 @@
 int self_signed_ok = 1;
 
-char *prog = "sst";
-char *host = NULL;
-char *port = NULL;
-char *method = NULL;
+const char *prog = "sst";
+const char *host = NULL;
+const char *port = NULL;
+const char *method = NULL;
 
 char certfbuf[MAXPATHLEN], ssldbuf[MAXPATHLEN];
@@ -316,6 +316,6 @@
  *	All rights reserved.
  */
-void
-ERR_log_errors()
+static void
+ERR_log_errors(void)
 {
 	unsigned long l;
@@ -333,5 +333,5 @@
 }
 
-void
+static void
 show_SSL_errors()
 {
@@ -340,4 +340,8 @@
 }
 
+#ifndef __GNUC__
+#	define __attribute__(x)
+#endif
+
 #define SHOW_x(L,F,x)	do { \
 	if (logging)	syslog((L), "%s", (x)); \
@@ -367,5 +371,5 @@
 
 
-char *usageopts[] = {
+static const char *usageopts[] = {
 "",
 " options:",
@@ -389,5 +393,5 @@
 "  -K pkey-file	= use <pkey-file> instead of the default private key file.",
 "  -D ssl-conf	= use <ssl-conf> as the path to default cert/keys.",
-"  -M method	= use a specific SSL method (ssl2, ssl3 or tls1).",
+"  -M method	= use a specific SSL method (ssl3 or tls1, etc.).",
 #ifdef USE_EGD
 "  -E skt-path	= use <skt-path> instead of the default EGD socket.",
@@ -403,7 +407,40 @@
 };
 
-usage()
+struct method {
+	const char *name;
+	const SSL_METHOD * (*meth)(void);
+} methods[] = {
+#if !defined(OPENSSL_NO_SSL2) && OPENSSL_VERSION_NUMBER < 0x1010000fL
+	{ "ssl2", SSLv2_method },
+#endif
+#if !defined(OPENSSL_NO_SSL3) && OPENSSL_VERSION_NUMBER < 0x1020000fL
+	{ "ssl3", SSLv3_method },
+#endif
+#if !defined(OPENSSL_NO_TLS1_METHOD)
+	{ "tls1", TLSv1_method },
+#endif
+#if !defined(OPENSSL_NO_TLS1_1_METHOD)
+	{ "tls1.1", TLSv1_1_method },
+#endif
+#if !defined(OPENSSL_NO_TLS1_2_METHOD)
+	{ "tls1.2", TLSv1_2_method },
+#endif
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	{ "dtls", DTLS_method },
+#endif
+#if !defined(OPENSSL_NO_DTLS1_METHOD) && OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	{ "dtls1", DTLSv1_method },
+#endif
+#if !defined(OPENSSL_NO_TLS1_2_METHOD) && OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	{ "dtls1.2", DTLSv1_2_method },
+#endif
+	{ NULL, SSLv23_method }
+};
+
+static void
+usage(void)
 {
-	char **uop = usageopts;
+	const char **uop = usageopts;
+	const struct method *m;
 
 	if (logging) {
@@ -415,9 +452,14 @@
 		while (*uop != NULL) fprintf(stderr, "%s\n", *uop++);
 	}
+	fprintf(stderr, " methods avalable for the -M option:\n");
+	fprintf(stderr, " -----------------------------------\n");
+	for (m = methods; m->name != NULL; m++)
+		fprintf(stderr, " %s", m->name);
+	fprintf(stderr, "\n");
 }
 
 /* reaper -- zombie prevention */
-void
-reaper()
+static void
+reaper(int signal __attribute__((unused)))
 {
 	int w;
@@ -459,4 +501,5 @@
  * - EOF on rd when in server mode means the actual server has finished.
  */
+static void
 relay(ssl, sd, rd, wd)
 SSL *ssl;
@@ -594,28 +637,10 @@
 
 	if (verbose) {
-		if (sizeof(off_t) > 4) {
-			if (ssl != NULL) {
-				SHOW_info1("bytes from   ssl: %qd", nsr);
-				SHOW_info1("bytes  to    ssl: %qd", nsw);
-			}
-			else {
-				SHOW_info1("bytes from remote: %qd", nsr);
-				SHOW_info1("bytes  to  remote: %qd", nsw);
-			}
-			SHOW_info1("bytes from local: %qd", nlr);
-			SHOW_info1("bytes  to  local: %qd", nlw);
-		}
-		else {
-			if (ssl != NULL) {
-				SHOW_info1("bytes from   ssl: %ld", nsr);
-				SHOW_info1("bytes  to    ssl: %ld", nsw);
-			}
-			else {
-				SHOW_info1("bytes from remote: %ld", nsr);
-				SHOW_info1("bytes  to  remote: %ld", nsw);
-			}
-			SHOW_info1("bytes from local: %ld", nlr);
-			SHOW_info1("bytes  to  local: %ld", nlw);
-		}
+		const char *id = ssl ? "ssl" : "remote";
+
+		SHOW_info2("bytes from %5s: %jd", id, (intmax_t)nsr);
+		SHOW_info2("bytes  to  %5s: %jd", id, (intmax_t)nsw);
+		SHOW_info1("bytes from local: %jd", (intmax_t)nlr);
+		SHOW_info1("bytes  to  local: %jd", (intmax_t)nlw);
 	}
 }
@@ -646,5 +671,5 @@
 
 	bp = X509_NAME_oneline(X509_get_subject_name(err_cert), 0, 0);
-	if (bp) { subj = strdup(bp); CRYPTO_free(bp); }
+	if (bp) { subj = strdup(bp); OPENSSL_free(bp); }
 
 	/*
@@ -688,9 +713,10 @@
 	switch (err) {
 	case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT:
-		bp = X509_NAME_oneline(X509_get_issuer_name(ctx->current_cert), 0, 0);
+		bp = X509_NAME_oneline(X509_get_issuer_name(
+		    X509_STORE_CTX_get_current_cert(ctx)), 0, 0);
 		if (bp == NULL) SHOW_err("verify: cert: no issuer.");
 		else {
 			if (debug > 1) SHOW_info1("verify: cert issuer: %s", bp);
-			CRYPTO_free(bp);
+			OPENSSL_free(bp);
 		}
 		break;
@@ -703,5 +729,5 @@
 }
 
-
+static void
 peer_cert_prep(ctx)
 SSL_CTX *ctx;
@@ -725,4 +751,5 @@
  * (note: beware of dynamic allocation)
  */
+static void
 peer_cert_chk(ctx, ssl)
 SSL_CTX *ctx;
@@ -751,5 +778,5 @@
 		else {
 			SHOW_info1("peer cert subject: %s", bp);
-			CRYPTO_free(bp);
+			OPENSSL_free(bp);
 		}
 
@@ -758,5 +785,5 @@
 		else {
 			SHOW_info1("peer cert issuer: %s", bp);
-			CRYPTO_free(bp);
+			OPENSSL_free(bp);
 		}
 	}
@@ -782,5 +809,5 @@
 }
 
-
+static void
 cert_prep(ctx)
 SSL_CTX *ctx;
@@ -804,5 +831,25 @@
 }
 
+static const SSL_METHOD *
+discern_ssl_method(requested)
+const char *requested;
+{
+	const struct method *m;
+
+	if (requested == NULL)
+		goto highest;
+
+	for (m = methods; m->name != NULL; m++) {
+		if (strcmp(m->name, requested) == 0)
+			return m->meth();
+	}
+
+	SHOW_info1("method `%s' not known, trying best available", requested);
+highest:
+	m = methods + sizeof(methods)/sizeof(methods[0]) - 1; /* Last entry */
+	return m->meth();
+}
 
+static void
 srvr_prep(ctx, ssl, sd)
 SSL_CTX **ctx;
@@ -811,6 +858,5 @@
 {
 	int err;
-	SSL_METHOD *meth;
-	X509 *client_cert;
+	const SSL_METHOD *meth;
 
 	/*
@@ -821,14 +867,5 @@
 	SSLeay_add_ssl_algorithms();
 
-	if (method == NULL)
-		meth = SSLv23_server_method();
-	else if (strcmp(method, "ssl2") == 0)
-		meth = SSLv2_server_method();
-	else if (strcmp(method, "ssl3") == 0)
-		meth = SSLv3_server_method();
-	else if (strcmp(method, "tls1") == 0)
-		meth = TLSv1_server_method();
-	else
-		meth = SSLv23_server_method();
+	meth = discern_ssl_method(method);
 
 	*ctx = SSL_CTX_new (meth);
@@ -854,5 +891,5 @@
 }
 
-
+static void
 clnt_prep(ctx, ssl, sd)
 SSL_CTX **ctx;
@@ -861,6 +898,5 @@
 {
 	int err;
-	SSL_METHOD *meth;
-	X509 *server_cert;
+	const SSL_METHOD *meth;
 
 	/*
@@ -871,14 +907,5 @@
 	SSLeay_add_ssl_algorithms();
 
-	if (method == NULL)
-		meth = SSLv23_client_method();
-	else if (strcmp(method, "ssl2") == 0)
-		meth = SSLv2_client_method();
-	else if (strcmp(method, "ssl3") == 0)
-		meth = SSLv3_client_method();
-	else if (strcmp(method, "tls1") == 0)
-		meth = TLSv1_client_method();
-	else
-		meth = SSLv23_client_method();
+	meth = discern_ssl_method(method);
 
 	*ctx = SSL_CTX_new (meth);
@@ -903,5 +930,5 @@
 }
 
-
+int
 main(ac, av)
 int ac;
@@ -958,5 +985,4 @@
 
 	if (errflg) {
-usage:
 		usage();
 		quit(1);
