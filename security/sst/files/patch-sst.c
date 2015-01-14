--- sst.c.orig	2000-05-04 19:47:28 UTC
+++ sst.c
@@ -212,7 +212,7 @@
  ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
  */
 #ifndef lint
-static char rcsid[] = "$Header: /local/src/local.bin/sst/SRC/RCS/sst.c,v 1.12 2000/05/04 19:47:26 pkern Exp $";
+static const char rcsid[] = "$Header: /local/src/local.bin/sst/SRC/RCS/sst.c,v 1.12 2000/05/04 19:47:26 pkern Exp $";
 #endif
 
 #include <stdio.h>
@@ -261,10 +261,10 @@ int timeout = 0;
 int inetd = 0;
 int eofclnt = 0;
 
-char *prog = "sst";
-char *host = NULL;
-char *port = NULL;
-char *method = NULL;
+const char *prog = "sst";
+const char *host = NULL;
+const char *port = NULL;
+const char *method = NULL;
 
 char certfbuf[MAXPATHLEN], ssldbuf[MAXPATHLEN];
 char *certf = NULL, *pkeyf = NULL, *ssld = NULL;
@@ -297,8 +297,8 @@ pid_t pid = 0;
  *	Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
  *	All rights reserved.
  */
-void
-ERR_log_errors()
+static void
+ERR_log_errors(void)
 {
 	unsigned long l;
 	char buf[200];
@@ -314,13 +314,17 @@ ERR_log_errors()
 	}
 }
 
-void
-show_SSL_errors()
+static void
+show_SSL_errors(void)
 {
 	if (logging)	ERR_log_errors();
 	else		ERR_print_errors_fp(stderr);
 }
 
+#ifndef __GNUC__
+#	define __attribute__(x)
+#endif
+
 #define SHOW_x(L,F,x)	{ \
 	if (logging)	syslog((L), "%s", (x)); \
 	else 		fprintf((F), "%d: %s\n", getpid(), (x)); }
@@ -346,7 +350,7 @@ show_SSL_errors()
 #define SHOW_info2(f,a1,a2)	SHOW_x2(LOG_DEBUG,tty,f,a1,a2)
 
 
-char *usageopts[] = {
+const char *usageopts[] = {
 "",
 " options:",
 " --------",
@@ -374,9 +378,10 @@ char *usageopts[] = {
 NULL
 };
 
-usage()
+static void
+usage(void)
 {
-	char **uop = usageopts;
+	const char **uop = usageopts;
 
 	if (logging) {
 		syslog(LOG_ERR, "usage: %s <options> [ '--' <auxiliary command + options> ]", prog);
@@ -389,8 +394,8 @@ usage()
 }
 
 /* reaper -- zombie prevention */
-void
-reaper()
+static void
+reaper(int signal __attribute__((unused)))
 {
 	int w;
 	pid_t p;
@@ -414,6 +419,7 @@ reaper()
  *
  * - EOF on rd when in server mode means the actual server has finished.
  */
+static void
 relay(ssl, sd, rd, wd)
 SSL *ssl;
 int sd, rd, wd;
@@ -522,22 +528,14 @@ done:
 	}
 
 	if (verbose) {
-		if (sizeof(off_t) > 4) {
-			SHOW_info1("bytes from   ssl: %qd", nsr);
-			SHOW_info1("bytes  to    ssl: %qd", nsw);
-			SHOW_info1("bytes from local: %qd", nlr);
-			SHOW_info1("bytes  to  local: %qd", nlw);
-		}
-		else {
-			SHOW_info1("bytes from   ssl: %ld", nsr);
-			SHOW_info1("bytes  to    ssl: %ld", nsw);
-			SHOW_info1("bytes from local: %ld", nlr);
-			SHOW_info1("bytes  to  local: %ld", nlw);
-		}
+		SHOW_info1("bytes from   ssl: %qd", (long long int)nsr);
+		SHOW_info1("bytes  to    ssl: %qd", (long long int)nsw);
+		SHOW_info1("bytes from local: %qd", (long long int)nlr);
+		SHOW_info1("bytes  to  local: %qd", (long long int)nlw);
 	}
 }
 
-
+static void
 srvr_prep(ctx, ssl, sd)
 SSL_CTX **ctx;
 SSL **ssl;
@@ -556,10 +554,14 @@ int sd;
 
 	if (method == NULL)
 		meth = SSLv23_server_method();
+#ifndef OPENSSL_NO_SSL2
 	else if (strcmp(method, "ssl2") == 0)
 		meth = SSLv2_server_method();
+#endif
+#ifndef OPENSSL_NO_SSL3_METHOD
 	else if (strcmp(method, "ssl3") == 0)
 		meth = SSLv3_server_method();
+#endif
 	else if (strcmp(method, "tls1") == 0)
 		meth = TLSv1_server_method();
 	else
@@ -609,8 +611,8 @@ int sd;
 			SHOW_info1("client cert subject: %s", subj);
 			SHOW_info1("client cert issuer: %s", issu);
 
-			Free(subj);
-			Free(issu);
+			free(subj);
+			free(issu);
     
 			/*
 			 * XXX ...
@@ -624,7 +626,7 @@ int sd;
 	}
 }
 
-
+static void
 clnt_prep(ctx, ssl, sd)
 SSL_CTX **ctx;
 SSL **ssl;
@@ -643,10 +645,14 @@ int sd;
 
 	if (method == NULL)
 		meth = SSLv23_client_method();
+#ifndef OPENSSL_NO_SSL2
 	else if (strcmp(method, "ssl2") == 0)
 		meth = SSLv2_client_method();
+#endif
+#ifndef OPENSSL_NO_SSL3_METHOD
 	else if (strcmp(method, "ssl3") == 0)
 		meth = SSLv3_client_method();
+#endif
 	else if (strcmp(method, "tls1") == 0)
 		meth = TLSv1_client_method();
 	else
@@ -699,8 +705,8 @@ int sd;
 		SHOW_info1("server cert subject: %s", subj);
 		SHOW_info1("server cert issuer: %s", issu);
 
-		Free(subj);
-		Free(issu);
+		free(subj);
+		free(issu);
 
 		/*
 		 * XXX ...
@@ -713,7 +719,7 @@ int sd;
 	X509_free (server_cert);
 }
 
-
+int
 main(ac, av)
 int ac;
 char *av[];
@@ -756,7 +762,6 @@ char *av[];
 	if (logging) openlog(prog, LOG_PID, LOG_SSL);
 
 	if (errflg) {
-usage:
 		usage();
 		exit(1);
 	}
