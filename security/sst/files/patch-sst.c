--- sst.c	2000-05-04 15:47:28.000000000 -0400
+++ sst.c	2013-06-20 08:55:27.000000000 -0400
@@ -213,5 +213,5 @@
  */
 #ifndef lint
-static char rcsid[] = "$Header: /local/src/local.bin/sst/SRC/RCS/sst.c,v 1.12 2000/05/04 19:47:26 pkern Exp $";
+static const char rcsid[] = "$Header: /local/src/local.bin/sst/SRC/RCS/sst.c,v 1.12 2000/05/04 19:47:26 pkern Exp $";
 #endif
 
@@ -262,8 +262,8 @@
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
@@ -298,6 +298,6 @@
  *	All rights reserved.
  */
-void
-ERR_log_errors()
+static void
+ERR_log_errors(void)
 {
 	unsigned long l;
@@ -315,6 +315,6 @@
 }
 
-void
-show_SSL_errors()
+static void
+show_SSL_errors(void)
 {
 	if (logging)	ERR_log_errors();
@@ -322,4 +322,8 @@
 }
 
+#ifndef __GNUC__
+#	define __attribute__(x)
+#endif
+
 #define SHOW_x(L,F,x)	{ \
 	if (logging)	syslog((L), "%s", (x)); \
@@ -347,5 +351,5 @@
 
 
-char *usageopts[] = {
+const char *usageopts[] = {
 "",
 " options:",
@@ -375,7 +379,8 @@
 };
 
-usage()
+static void
+usage(void)
 {
-	char **uop = usageopts;
+	const char **uop = usageopts;
 
 	if (logging) {
@@ -390,6 +395,6 @@
 
 /* reaper -- zombie prevention */
-void
-reaper()
+static void
+reaper(int signal __attribute__((unused)))
 {
 	int w;
@@ -415,4 +420,5 @@
  * - EOF on rd when in server mode means the actual server has finished.
  */
+static void
 relay(ssl, sd, rd, wd)
 SSL *ssl;
@@ -523,20 +529,12 @@
 
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
@@ -610,6 +608,6 @@
 			SHOW_info1("client cert issuer: %s", issu);
 
-			Free(subj);
-			Free(issu);
+			free(subj);
+			free(issu);
     
 			/*
@@ -625,5 +623,5 @@
 }
 
-
+static void
 clnt_prep(ctx, ssl, sd)
 SSL_CTX **ctx;
@@ -700,6 +698,6 @@
 		SHOW_info1("server cert issuer: %s", issu);
 
-		Free(subj);
-		Free(issu);
+		free(subj);
+		free(issu);
 
 		/*
@@ -714,5 +712,5 @@
 }
 
-
+int
 main(ac, av)
 int ac;
@@ -757,5 +755,4 @@
 
 	if (errflg) {
-usage:
 		usage();
 		exit(1);
