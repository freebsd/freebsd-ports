--- main.c.orig	2016-07-24 05:54:33 UTC
+++ main.c
@@ -30,6 +30,8 @@
 
 #include "extern.h"
 
+#define AGREEMENT "https://letsencrypt.org" \
+		  "/documents/LE-SA-v1.1.1-August-1-2016.pdf"
 #define SSL_DIR "/etc/ssl/letsencrypt"
 #define SSL_PRIV_DIR "/etc/ssl/letsencrypt/private"
 #define ETC_DIR "/etc/letsencrypt"
@@ -74,7 +76,7 @@ doasprintf(const char *fmt, ...)
 int
 main(int argc, char *argv[])
 {
-	const char	 *domain;
+	const char	 *domain, *agreement;
 	char	 	 *certdir, *acctkey, *chngdir, *keyfile;
 	int		  key_fds[2], acct_fds[2], chng_fds[2], 
 			  cert_fds[2], file_fds[2], dns_fds[2],
@@ -91,9 +93,13 @@ main(int argc, char *argv[])
 	newacct = remote = revoke = verbose = force = 
 		multidir = staging = newkey = 0;
 	certdir = keyfile = acctkey = chngdir = NULL;
+	agreement = AGREEMENT;
 
-	while (-1 != (c = getopt(argc, argv, "FmnNrstvf:c:C:k:"))) 
+	while (-1 != (c = getopt(argc, argv, "bFmnNrstva:f:c:C:k:")))
 		switch (c) {
+		case ('a'):
+			agreement = optarg;
+			break;
 		case ('c'):
 			free(certdir);
 			if (NULL == (certdir = strdup(optarg)))
@@ -282,7 +288,8 @@ main(int argc, char *argv[])
 			chng_fds[1], cert_fds[1], 
 			dns_fds[1], rvk_fds[1], 
 			newacct, revoke, staging,
-			(const char *const *)alts, altsz);
+			(const char *const *)alts, altsz,
+			agreement);
 		free(alts);
 		exit(c ? EXIT_SUCCESS : EXIT_FAILURE);
 	}
@@ -459,7 +466,8 @@ main(int argc, char *argv[])
 	       (2 == c ? EXIT_SUCCESS : 2));
 usage:
 	fprintf(stderr, "usage: %s "
-		"[-FnNrsv] "
+		"[-bFmnNrsv] "
+		"[-a agreement] "
 		"[-C challengedir] "
 		"[-c certdir] "
 		"[-f accountkey] "
