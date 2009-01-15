--- ssmtp.c.orig	2004-07-23 01:58:48.000000000 -0400
+++ ssmtp.c	2009-01-15 14:13:10.000000000 -0500
@@ -12,8 +12,9 @@
  See COPYRIGHT for the license
 
 */
-#define VERSION "2.60.4"
+#define VERSION "2.61-11.1"
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <sys/param.h>
@@ -54,20 +55,20 @@
 
 #define ARPADATE_LENGTH 32		/* Current date in RFC format */
 char arpadate[ARPADATE_LENGTH];
-char *auth_user = (char)NULL;
-char *auth_pass = (char)NULL;
-char *auth_method = (char)NULL;		/* Mechanism for SMTP authentication */
-char *mail_domain = (char)NULL;
-char *from = (char)NULL;		/* Use this as the From: address */
+char *auth_user = NULL;
+char *auth_pass = NULL;
+char *auth_method = NULL;		/* Mechanism for SMTP authentication */
+char *mail_domain = NULL;
+char *from = NULL;		/* Use this as the From: address */
 char hostname[MAXHOSTNAMELEN] = "localhost";
 char *mailhost = "mailhub";
-char *minus_f = (char)NULL;
-char *minus_F = (char)NULL;
+char *minus_f = NULL;
+char *minus_F = NULL;
 char *gecos;
-char *prog = (char)NULL;
+char *prog = NULL;
 char *root = NULL;
 char *tls_cert = "/etc/ssl/certs/ssmtp.pem";	/* Default Certificate */
-char *uad = (char)NULL;
+char *uad = NULL;
 
 headers_t headers, *ht;
 
@@ -220,16 +221,16 @@
 	char buf[MAXPATHLEN +1], *p;
 
 	if((p = strrchr(str, '/'))) {
-		if(strncpy(buf, ++p, MAXPATHLEN) == (char *)NULL) {
+		if(strncpy(buf, ++p, MAXPATHLEN) == NULL) {
 			die("basename() -- strncpy() failed");
 		}
 	}
 	else {
-		if(strncpy(buf, str, MAXPATHLEN) == (char *)NULL) {
+		if(strncpy(buf, str, MAXPATHLEN) == NULL) {
 			die("basename() -- strncpy() failed");
 		}
 	}
-	buf[MAXPATHLEN] = (char)NULL;
+	buf[MAXPATHLEN] = '\0';
 
 	return(strdup(buf));
 }
@@ -256,7 +257,7 @@
 
 	p = (str + strlen(str));
 	while(isspace(*--p)) {
-		*p = (char)NULL;
+		*p = '\0';
 	}
 
 	return(p);
@@ -274,7 +275,7 @@
 #endif
 
 	/* Simple case with email address enclosed in <> */
-	if((p = strdup(str)) == (char *)NULL) {
+	if((p = strdup(str)) == NULL) {
 		die("addr_parse(): strdup()");
 	}
 
@@ -282,7 +283,7 @@
 		q++;
 
 		if((p = strchr(q, '>'))) {
-			*p = (char)NULL;
+			*p = '\0';
 		}
 
 #if 0
@@ -305,7 +306,7 @@
 	q = strip_post_ws(p);
 	if(*q == ')') {
 		while((*--q != '('));
-		*q = (char)NULL;
+		*q = '\0';
 	}
 	(void)strip_post_ws(p);
 
@@ -323,7 +324,7 @@
 {
 	char buf[(BUF_SZ + 1)];
 
-	if(strchr(str, '@') == (char *)NULL) {
+	if(strchr(str, '@') == NULL) {
 		if(snprintf(buf, BUF_SZ, "%s@%s", str,
 #ifdef REWRITE_DOMAIN
 			rewrite_domain == True ? mail_domain : hostname
@@ -348,7 +349,7 @@
 	char *p;
 
 	if((p = strchr(str, '\n'))) {
-		*p = (char)NULL;
+		*p = '\0';
 	}
 
 	/* Any line beginning with a dot has an additional dot inserted;
@@ -374,31 +375,58 @@
 {
 	char buf[(BUF_SZ + 1)], *p;
 	FILE *fp;
+#ifdef USERPREFS
+	char *file=NULL;
+	if (pw->pw_dir != NULL) {
+		file = (char *)malloc (strlen (pw->pw_dir) + 1 + strlen (".ssmtprc") + 1);
+		sprintf (file, "%s/.ssmtprc", pw->pw_dir);
+	}
+
+	if ((file != NULL) && (fp = fopen(file, "r")) ) {
+		while(fgets(buf, sizeof(buf), fp)) {
+				/* Make comments invisible */
+				if((p = strchr(buf, '#'))) {
+					*p = '\0';
+				}
 
+			/* Ignore malformed lines and comments */
+				if(strchr(buf, '@') == NULL) {
+					continue;
+				}
+				if((p = strtok(buf, "\n"))) {
+                                        if((uad = strdup(p)) == NULL) {
+                                                die("revaliases() -- strdup() failed");
+                                        }
+				}
+			}
+		fclose(fp);
 	/* Try to open the reverse aliases file */
-	if((fp = fopen(REVALIASES_FILE, "r"))) {
+	} else if ((fp = fopen(REVALIASES_FILE, "r"))) {
+#else
+	if ((fp = fopen(REVALIASES_FILE, "r"))) {
+#endif
 		/* Search if a reverse alias is defined for the sender */
 		while(fgets(buf, sizeof(buf), fp)) {
 			/* Make comments invisible */
 			if((p = strchr(buf, '#'))) {
-				*p = (char)NULL;
+				*p = '\0';
 			}
 
 			/* Ignore malformed lines and comments */
-			if(strchr(buf, ':') == (char *)NULL) {
+			if(strchr(buf, ':') == NULL) {
 				continue;
 			}
 
 			/* Parse the alias */
 			if(((p = strtok(buf, ":"))) && !strcmp(p, pw->pw_name)) {
 				if((p = strtok(NULL, ": \t\r\n"))) {
-					if((uad = strdup(p)) == (char *)NULL) {
+					if((uad = strdup(p)) == NULL) {
 						die("revaliases() -- strdup() failed");
 					}
 				}
 
 				if((p = strtok(NULL, " \t\r\n:"))) {
-					if((mailhost = strdup(p)) == (char *)NULL) {
+					if((mailhost = strdup(p)) == NULL) {
 						die("revaliases() -- strdup() failed");
 					}
 
@@ -435,7 +463,7 @@
 	}
 
 	/* Remove the real name if necessary - just send the address */
-	if((p = addr_parse(str)) == (char *)NULL) {
+	if((p = addr_parse(str)) == NULL) {
 		die("from_strip() -- addr_parse() failed");
 	}
 #if 0
@@ -511,11 +539,11 @@
 #endif
 
 	/* Ignore missing usernames */
-	if(*str == (char)NULL) {
+	if(*str == '\0') {
 		return;
 	}
 
-	if((rt->string = strdup(str)) == (char *)NULL) {
+	if((rt->string = strdup(str)) == NULL) {
 		die("rcpt_save() -- strdup() failed");
 	}
 
@@ -540,7 +568,7 @@
 	(void)fprintf(stderr, "*** rcpt_parse(): str = [%s]\n", str);
 #endif
 
-	if((p = strdup(str)) == (char *)NULL) {
+	if((p = strdup(str)) == NULL) {
 		die("rcpt_parse(): strdup() failed");
 	}
 	q = p;
@@ -568,7 +596,7 @@
 		}
 
 		/* End of string? */
-		if(*(q + 1) == (char)NULL) {
+		if(*(q + 1) == '\0') {
 			got_addr = True;
 		}
 
@@ -576,7 +604,7 @@
 		if((*q == ',') && (in_quotes == False)) {
 			got_addr = True;
 
-			*q = (char)NULL;
+			*q = '\0';
 		}
 
 		if(got_addr) {
@@ -599,19 +627,21 @@
 {
 	int i;
 	unsigned char digest[MD5_DIGEST_LEN];
-	unsigned char digascii[MD5_DIGEST_LEN * 2];
+	char digascii[MD5_DIGEST_LEN * 2];
 	unsigned char challenge[(BUF_SZ + 1)];
-	unsigned char response[(BUF_SZ + 1)];
-	unsigned char secret[(MD5_BLOCK_LEN + 1)]; 
+	char response[(BUF_SZ + 1)];
+	char secret[(MD5_BLOCK_LEN + 1)]; 
+	int challenge_len;
 
 	memset (secret,0,sizeof(secret));
 	memset (challenge,0,sizeof(challenge));
 	strncpy (secret, password, sizeof(secret));	
 	if (!challengeb64 || strlen(challengeb64) > sizeof(challenge) * 3 / 4)
 		return 0;
-	from64tobits(challenge, challengeb64);
+	challenge_len = from64tobits(challenge, challengeb64);
 
-	hmac_md5(challenge, strlen(challenge), secret, strlen(secret), digest);
+	hmac_md5(challenge, challenge_len, 
+		 (unsigned char *)secret, strlen(secret), digest);
 
 	for (i = 0; i < MD5_DIGEST_LEN; i++) {
 		digascii[2 * i] = hextab[digest[i] >> 4];
@@ -625,7 +655,7 @@
 	strncpy (response, username, sizeof(response) - sizeof(digascii) - 2);
 	strcat (response, " ");
 	strcat (response, digascii);
-	to64frombits(responseb64, response, strlen(response));
+	to64frombits(responseb64, (unsigned char *)response, strlen(response));
 
 	return 1;
 }
@@ -660,7 +690,7 @@
 	(void)fprintf(stderr, "header_save(): str = [%s]\n", str);
 #endif
 
-	if((p = strdup(str)) == (char *)NULL) {
+	if((p = strdup(str)) == NULL) {
 		die("header_save() -- strdup() failed");
 	}
 	ht->string = p;
@@ -668,7 +698,7 @@
 	if(strncasecmp(ht->string, "From:", 5) == 0) {
 #if 1
 		/* Hack check for NULL From: line */
-		if(*(p + 6) == (char)NULL) {
+		if(*(p + 6) == '\0') {
 			return;
 		}
 #endif
@@ -727,19 +757,19 @@
 void header_parse(FILE *stream)
 {
 	size_t size = BUF_SZ, len = 0;
-	char *p = (char *)NULL, *q;
+	char *p = NULL, *q = NULL;
 	bool_t in_header = True;
-	char l = (char)NULL;
+	char l = '\0';
 	int c;
 
 	while(in_header && ((c = fgetc(stream)) != EOF)) {
 		/* Must have space for up to two more characters, since we
 			may need to insert a '\r' */
-		if((p == (char *)NULL) || (len >= (size - 1))) {
+		if((p == NULL) || (len >= (size - 1))) {
 			size += BUF_SZ;
 
 			p = (char *)realloc(p, (size * sizeof(char)));
-			if(p == (char *)NULL) {
+			if(p == NULL) {
 				die("header_parse() -- realloc() failed");
 			}
 			q = (p + len);
@@ -764,9 +794,9 @@
 						in_header = False;
 
 				default:
-						*q = (char)NULL;
+						*q = '\0';
 						if((q = strrchr(p, '\n'))) {
-							*q = (char)NULL;
+							*q = '\0';
 						}
 						header_save(p);
 
@@ -796,17 +826,17 @@
 	while(fgets(buf, sizeof(buf), fp)) {
 		/* Make comments invisible */
 		if((p = strchr(buf, '#'))) {
-			*p = (char)NULL;
+			*p = '\0';
 		}
 
 		/* Ignore malformed lines and comments */
-		if(strchr(buf, '=') == (char *)NULL) continue;
+		if(strchr(buf, '=') == NULL) continue;
 
 		/* Parse out keywords */
-		if(((p = strtok(buf, "= \t\n")) != (char *)NULL)
-			&& ((q = strtok(NULL, "= \t\n:")) != (char *)NULL)) {
+		if(((p = strtok(buf, "= \t\n")) != NULL)
+			&& ((q = strtok(NULL, "= \t\n:")) != NULL)) {
 			if(strcasecmp(p, "Root") == 0) {
-				if((root = strdup(q)) == (char *)NULL) {
+				if((root = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -815,7 +845,7 @@
 				}
 			}
 			else if(strcasecmp(p, "MailHub") == 0) {
-				if((mailhost = strdup(q)) == (char *)NULL) {
+				if((mailhost = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -851,7 +881,7 @@
 					mail_domain = strdup(q);
 				}
 
-				if(mail_domain == (char *)NULL) {
+				if(mail_domain == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 				rewrite_domain = True;
@@ -927,7 +957,7 @@
 				}
 			}
 			else if(strcasecmp(p, "TLSCert") == 0) {
-				if((tls_cert = strdup(q)) == (char *)NULL) {
+				if((tls_cert = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -938,7 +968,7 @@
 #endif
 			/* Command-line overrides these */
 			else if(strcasecmp(p, "AuthUser") == 0 && !auth_user) {
-				if((auth_user = strdup(q)) == (char *)NULL) {
+				if((auth_user = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -947,7 +977,7 @@
 				}
 			}
 			else if(strcasecmp(p, "AuthPass") == 0 && !auth_pass) {
-				if((auth_pass = strdup(q)) == (char *)NULL) {
+				if((auth_pass = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -956,7 +986,7 @@
 				}
 			}
 			else if(strcasecmp(p, "AuthMethod") == 0 && !auth_method) {
-				if((auth_method = strdup(q)) == (char *)NULL) {
+				if((auth_method = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -982,11 +1012,11 @@
 #ifdef INET6
 	struct addrinfo hints, *ai0, *ai;
 	char servname[NI_MAXSERV];
-	int s;
+	int s = -1;
 #else
 	struct sockaddr_in name;
 	struct hostent *hent;
-	int s, namelen;
+	int s = -1, namelen;
 #endif
 
 #ifdef HAVE_SSL
@@ -996,7 +1026,7 @@
 	/* Init SSL stuff */
 	SSL_CTX *ctx;
 	SSL_METHOD *meth;
-	X509 *server_cert;
+	const X509 *server_cert;
 
 	SSL_load_error_strings();
 	SSLeay_add_ssl_algorithms();
@@ -1179,7 +1209,7 @@
 			buf[i++] = c;
 		}
 	}
-	buf[i] = (char)NULL;
+	buf[i] = '\0';
 
 	return(buf);
 }
@@ -1293,14 +1323,14 @@
 	}
 
 	if((p = strtok(pw->pw_gecos, ";,"))) {
-		if((gecos = strdup(p)) == (char *)NULL) {
+		if((gecos = strdup(p)) == NULL) {
 			die("ssmtp() -- strdup() failed");
 		}
 	}
 	revaliases(pw);
 
 	/* revaliases() may have defined this */
-	if(uad == (char *)NULL) {
+	if(uad == NULL) {
 		uad = append_domain(pw->pw_name);
 	}
 
@@ -1349,7 +1379,7 @@
 	/* Try to log in if username was supplied */
 	if(auth_user) {
 #ifdef MD5AUTH
-		if(auth_pass == (char *)NULL) {
+		if(auth_pass == NULL) {
 			auth_pass = strdup("");
 		}
 
@@ -1377,7 +1407,7 @@
 		}
 		memset(buf, 0, sizeof(buf));
 
-		to64frombits(buf, auth_pass, strlen(auth_pass));
+		to64frombits(buf, (unsigned char *)auth_pass, strlen(auth_pass));
 #ifdef MD5AUTH
 		}
 #endif
@@ -1549,7 +1579,7 @@
 		j = 0;
 
 		add = 1;
-		while(argv[i][++j] != (char)NULL) {
+		while(argv[i][++j] != '\0') {
 			switch(argv[i][j]) {
 #ifdef INET6
 			case '6':
@@ -1567,14 +1597,14 @@
 					if((!argv[i][(j + 1)])
 						&& argv[(i + 1)]) {
 						auth_user = strdup(argv[i+1]);
-						if(auth_user == (char *)NULL) {
+						if(auth_user == NULL) {
 							die("parse_options() -- strdup() failed");
 						}
 						add++;
 					}
 					else {
 						auth_user = strdup(argv[i]+j+1);
-						if(auth_user == (char *)NULL) {
+						if(auth_user == NULL) {
 							die("parse_options() -- strdup() failed");
 						}
 					}
@@ -1584,14 +1614,14 @@
 					if((!argv[i][(j + 1)])
 						&& argv[(i + 1)]) {
 						auth_pass = strdup(argv[i+1]);
-						if(auth_pass == (char *)NULL) {
+						if(auth_pass == NULL) {
 							die("parse_options() -- strdup() failed");
 						}
 						add++;
 					}
 					else {
 						auth_pass = strdup(argv[i]+j+1);
-						if(auth_pass == (char *)NULL) {
+						if(auth_pass == NULL) {
 							die("parse_options() -- strdup() failed");
 						}
 					}
@@ -1669,14 +1699,14 @@
 			case 'F':
 				if((!argv[i][(j + 1)]) && argv[(i + 1)]) {
 					minus_F = strdup(argv[(i + 1)]);
-					if(minus_F == (char *)NULL) {
+					if(minus_F == NULL) {
 						die("parse_options() -- strdup() failed");
 					}
 					add++;
 				}
 				else {
 					minus_F = strdup(argv[i]+j+1);
-					if(minus_F == (char *)NULL) {
+					if(minus_F == NULL) {
 						die("parse_options() -- strdup() failed");
 					}
 				}
@@ -1688,14 +1718,14 @@
 			case 'r':
 				if((!argv[i][(j + 1)]) && argv[(i + 1)]) {
 					minus_f = strdup(argv[(i + 1)]);
-					if(minus_f == (char *)NULL) {
+					if(minus_f == NULL) {
 						die("parse_options() -- strdup() failed");
 					}
 					add++;
 				}
 				else {
 					minus_f = strdup(argv[i]+j+1);
-					if(minus_f == (char *)NULL) {
+					if(minus_f == NULL) {
 						die("parse_options() -- strdup() failed");
 					}
 				}
