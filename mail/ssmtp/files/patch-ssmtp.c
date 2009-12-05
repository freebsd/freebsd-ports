--- ssmtp.c.orig	2008-03-06 22:01:22.000000000 +0200
+++ ssmtp.c	2009-12-04 02:22:14.000000000 +0200
@@ -10,7 +10,7 @@
  See COPYRIGHT for the license
 
 */
-#define VERSION "2.62"
+#define VERSION "2.62.3"
 #define _GNU_SOURCE
 
 #include <sys/socket.h>
@@ -25,6 +25,7 @@
 #include <string.h>
 #include <ctype.h>
 #include <netdb.h>
+#include <libgen.h>
 #ifdef HAVE_SSL
 #include <openssl/crypto.h>
 #include <openssl/x509.h>
@@ -55,21 +56,21 @@
 
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
 char *hostname;
 char *mailhost = "mailhub";
-char *minus_f = (char)NULL;
-char *minus_F = (char)NULL;
+char *minus_f = NULL;
+char *minus_F = NULL;
 char *gecos;
-char *prog = (char)NULL;
+char *prog = NULL;
 char *root = NULL;
-char *tls_cert = "/etc/ssl/certs/ssmtp.pem";	/* Default Certificate */
-char *uad = (char)NULL;
-char *config_file = (char)NULL;		/* alternate configuration file */
+char *tls_cert = "/usr/local/etc/ssmtp/ssmtp.pem";	/* Default Certificate */
+char *uad = NULL;
+char *config_file = NULL;		/* alternate configuration file */
 
 headers_t headers, *ht;
 
@@ -239,6 +240,24 @@
 }
 #endif /* _GNU_SOURCE */
 
+#if defined(__FreeBSD_version) && __FreeBSD_version < 701101
+char *
+strndup(const char *str, size_t n)
+{
+	size_t len;
+	char *copy;
+
+	for (len = 0; len < n && str[len]; len++)
+		continue;
+
+	if ((copy = malloc(len + 1)) == NULL)
+		return (NULL);
+	memcpy(copy, str, len);
+	copy[len] = '\0';
+	return (copy);
+}
+#endif
+
 /*
 strip_pre_ws() -- Return pointer to first non-whitespace character
 */
@@ -261,7 +280,7 @@
 
 	p = (str + strlen(str));
 	while(isspace(*--p)) {
-		*p = (char)NULL;
+		*p = '\0';
 	}
 
 	return(p);
@@ -279,7 +298,7 @@
 #endif
 
 	/* Simple case with email address enclosed in <> */
-	if((p = strdup(str)) == (char *)NULL) {
+	if((p = strdup(str)) == NULL) {
 		die("addr_parse(): strdup()");
 	}
 
@@ -287,7 +306,7 @@
 		q++;
 
 		if((p = strchr(q, '>'))) {
-			*p = (char)NULL;
+			*p = '\0';
 		}
 
 #if 0
@@ -310,7 +329,7 @@
 	q = strip_post_ws(p);
 	if(*q == ')') {
 		while((*--q != '('));
-		*q = (char)NULL;
+		*q = '\0';
 	}
 	(void)strip_post_ws(p);
 
@@ -347,28 +366,26 @@
 /*
 standardise() -- Trim off '\n's and double leading dots
 */
-void standardise(char *str)
+bool_t standardise(char *str, bool_t *linestart)
 {
 	size_t sl;
 	char *p;
-
-	if((p = strchr(str, '\n'))) {
-		*p = (char)NULL;
-	}
+	bool_t leadingdot = False;
 
 	/* Any line beginning with a dot has an additional dot inserted;
-	not just a line consisting solely of a dot. Thus we have to slide
-	the buffer down one */
-	sl = strlen(str);
+	not just a line consisting solely of a dot. Thus we have to move
+	the buffer start up one */
 
-	if(*str == '.') {
-		if((sl + 2) > BUF_SZ) {
-			die("standardise() -- Buffer overflow");
-		}
-		(void)memmove((str + 1), str, (sl + 1));	/* Copy trailing \0 */
+	if(*linestart && *str == '.') {
+		leadingdot = True;
+	}
+	*linestart = False;
 
-		*str = '.';
+	if((p = strchr(str, '\n'))) {
+		*p = '\0';
+		*linestart = True;
 	}
+	return(leadingdot);
 }
 
 /*
@@ -386,7 +403,7 @@
 		while(fgets(buf, sizeof(buf), fp)) {
 			/* Make comments invisible */
 			if((p = strchr(buf, '#'))) {
-				*p = (char)NULL;
+				*p = '\0';
 			}
 
 			/* Ignore malformed lines and comments */
@@ -485,6 +502,11 @@
 				die("from_format() -- snprintf() failed");
 			}
 		}
+		else {
+			if(snprintf(buf, BUF_SZ, "%s", str) == -1) {
+				die("from_format() -- snprintf() failed");
+			}
+		}
 	}
 
 #if 0
@@ -516,11 +538,11 @@
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
 
@@ -545,7 +567,7 @@
 	(void)fprintf(stderr, "*** rcpt_parse(): str = [%s]\n", str);
 #endif
 
-	if((p = strdup(str)) == (char *)NULL) {
+	if((p = strdup(str)) == NULL) {
 		die("rcpt_parse(): strdup() failed");
 	}
 	q = p;
@@ -573,7 +595,7 @@
 		}
 
 		/* End of string? */
-		if(*(q + 1) == (char)NULL) {
+		if(*(q + 1) == '\0') {
 			got_addr = True;
 		}
 
@@ -581,7 +603,7 @@
 		if((*q == ',') && (in_quotes == False)) {
 			got_addr = True;
 
-			*q = (char)NULL;
+			*q = '\0';
 		}
 
 		if(got_addr) {
@@ -665,7 +687,7 @@
 	(void)fprintf(stderr, "header_save(): str = [%s]\n", str);
 #endif
 
-	if((p = strdup(str)) == (char *)NULL) {
+	if((p = strdup(str)) == NULL) {
 		die("header_save() -- strdup() failed");
 	}
 	ht->string = p;
@@ -673,7 +695,7 @@
 	if(strncasecmp(ht->string, "From:", 5) == 0) {
 #if 1
 		/* Hack check for NULL From: line */
-		if(*(p + 6) == (char)NULL) {
+		if(*(p + 6) == '\0') {
 			return;
 		}
 #endif
@@ -736,19 +758,19 @@
 void header_parse(FILE *stream)
 {
 	size_t size = BUF_SZ, len = 0;
-	char *p = (char *)NULL, *q;
+	char *p = NULL, *q;
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
@@ -773,9 +795,9 @@
 						in_header = False;
 
 				default:
-						*q = (char)NULL;
+						*q = '\0';
 						if((q = strrchr(p, '\n'))) {
-							*q = (char)NULL;
+							*q = '\0';
 						}
 						header_save(p);
 
@@ -806,9 +828,9 @@
 						in_header = False;
 
 				default:
-						*q = (char)NULL;
+						*q = '\0';
 						if((q = strrchr(p, '\n'))) {
-							*q = (char)NULL;
+							*q = '\0';
 						}
 						header_save(p);
 
@@ -873,11 +895,11 @@
 		char *rightside;
 		/* Make comments invisible */
 		if((p = strchr(buf, '#'))) {
-			*p = (char)NULL;
+			*p = '\0';
 		}
 
 		/* Ignore malformed lines and comments */
-		if(strchr(buf, '=') == (char *)NULL) continue;
+		if(strchr(buf, '=') == NULL) continue;
 
 		/* Parse out keywords */
 		p=firsttok(&begin, "= \t\n");
@@ -887,7 +909,7 @@
 		}
 		if(p && q) {
 			if(strcasecmp(p, "Root") == 0) {
-				if((root = strdup(q)) == (char *)NULL) {
+				if((root = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -896,7 +918,7 @@
 				}
 			}
 			else if(strcasecmp(p, "MailHub") == 0) {
-				if((mailhost = strdup(q)) == (char *)NULL) {
+				if((mailhost = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -946,7 +968,7 @@
 					mail_domain = strdup(q);
 				}
 
-				if(mail_domain == (char *)NULL) {
+				if(mail_domain == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 				rewrite_domain = True;
@@ -1022,7 +1044,7 @@
 				}
 			}
 			else if(strcasecmp(p, "TLSCert") == 0) {
-				if((tls_cert = strdup(q)) == (char *)NULL) {
+				if((tls_cert = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -1033,7 +1055,7 @@
 #endif
 			/* Command-line overrides these */
 			else if(strcasecmp(p, "AuthUser") == 0 && !auth_user) {
-				if((auth_user = strdup(q)) == (char *)NULL) {
+				if((auth_user = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -1042,7 +1064,7 @@
 				}
 			}
 			else if(strcasecmp(p, "AuthPass") == 0 && !auth_pass) {
-				if((auth_pass = strdup(q)) == (char *)NULL) {
+				if((auth_pass = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -1051,7 +1073,7 @@
 				}
 			}
 			else if(strcasecmp(p, "AuthMethod") == 0 && !auth_method) {
-				if((auth_method = strdup(q)) == (char *)NULL) {
+				if((auth_method = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -1104,11 +1126,11 @@
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
@@ -1301,7 +1323,7 @@
 			buf[i++] = c;
 		}
 	}
-	buf[i] = (char)NULL;
+	buf[i] = '\0';
 
 	return(buf);
 }
@@ -1356,12 +1378,12 @@
 */
 ssize_t smtp_write(int fd, char *format, ...)
 {
-	char buf[(BUF_SZ + 1)];
+	char buf[(BUF_SZ + 2)];
 	va_list ap;
 	ssize_t outbytes = 0;
 
 	va_start(ap, format);
-	if(vsnprintf(buf, (BUF_SZ - 2), format, ap) == -1) {
+	if(vsnprintf(buf, (BUF_SZ - 1), format, ap) == -1) {
 		die("smtp_write() -- vsnprintf() failed");
 	}
 	va_end(ap);
@@ -1399,16 +1421,18 @@
 */
 int ssmtp(char *argv[])
 {
-	char buf[(BUF_SZ + 1)], *p, *q;
+	char b[(BUF_SZ + 2)], *buf = b+1, *p, *q;
 #ifdef MD5AUTH
 	char challenge[(BUF_SZ + 1)];
 #endif
 	struct passwd *pw;
 	int i, sock;
 	uid_t uid;
-	bool_t minus_v_save;
+	bool_t minus_v_save, leadingdot, linestart = True;
 	int timeout = 0;
+	int bufsize = sizeof(b)-1;
 
+	b[0] = '.';
 	outbytes = 0;
 	ht = &headers;
 
@@ -1423,14 +1447,14 @@
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
 
@@ -1478,7 +1502,7 @@
 	/* Try to log in if username was supplied */
 	if(auth_user) {
 #ifdef MD5AUTH
-		if(auth_pass == (char *)NULL) {
+		if(auth_pass == NULL) {
 			auth_pass = strdup("");
 		}
 
@@ -1491,12 +1515,12 @@
 			}
 			strncpy(challenge, strchr(buf,' ') + 1, sizeof(challenge));
 
-			memset(buf, 0, sizeof(buf));
+			memset(buf, 0, bufsize);
 			crammd5(challenge, auth_user, auth_pass, buf);
 		}
 		else {
 #endif
-		memset(buf, 0, sizeof(buf));
+		memset(buf, 0, bufsize);
 		to64frombits(buf, auth_user, strlen(auth_user));
 		if (use_oldauth) {
 			outbytes += smtp_write(sock, "AUTH LOGIN %s", buf);
@@ -1508,7 +1532,7 @@
 				die("Server didn't like our AUTH LOGIN (%s)", buf);
 			}
 			/* we assume server asked us for Username */
-			memset(buf, 0, sizeof(buf));
+			memset(buf, 0, bufsize);
 			to64frombits(buf, auth_user, strlen(auth_user));
 			outbytes += smtp_write(sock, buf);
 		}
@@ -1517,7 +1541,7 @@
 		if(smtp_read(sock, buf) != 3) {
 			die("Server didn't accept AUTH LOGIN (%s)", buf);
 		}
-		memset(buf, 0, sizeof(buf));
+		memset(buf, 0, bufsize);
 
 		to64frombits(buf, auth_pass, strlen(auth_pass));
 #ifdef MD5AUTH
@@ -1626,28 +1650,40 @@
 	  stdio functions like fgets in the first place */
 	fcntl(STDIN_FILENO,F_SETFL,O_NONBLOCK);
 
-	/* don't hang forever when reading from stdin */
-	while(!feof(stdin) && timeout < MEDWAIT) {
-		if (!fgets(buf, sizeof(buf), stdin)) {
+	while(!feof(stdin)) {
+		if (!fgets(buf, bufsize, stdin)) {
 			/* if nothing was received, then no transmission
 			 * over smtp should be done */
 			sleep(1);
-			timeout++;
+			/* don't hang forever when reading from stdin */
+			if (++timeout >= MEDWAIT) {
+				log_event(LOG_ERR, "killed: timeout on stdin while reading body -- message saved to dead.letter.");
+				die("Timeout on stdin while reading body");
+			}
 			continue;
 		}
 		/* Trim off \n, double leading .'s */
-		standardise(buf);
-
-		outbytes += smtp_write(sock, "%s", buf);
+		leadingdot = standardise(buf, &linestart);
 
+		if (linestart || feof(stdin)) {
+			linestart = True;
+			outbytes += smtp_write(sock, "%s", leadingdot ? b : buf);
+		} else {
+			if (log_level > 0) {
+				log_event(LOG_INFO, "Sent a very long line in chunks");
+			}
+			if (leadingdot) {
+				outbytes += fd_puts(sock, b, sizeof(b));
+			} else {
+				outbytes += fd_puts(sock, buf, bufsize);
+			}
+		}
 		(void)alarm((unsigned) MEDWAIT);
 	}
-	/* End of body */
-
-	if (timeout >= MEDWAIT) {
-		log_event(LOG_ERR, "killed: timeout on stdin while reading body -- message saved to dead.letter.");
-		die("Timeout on stdin while reading body");
+	if(!linestart) {
+		smtp_write(sock, "");
 	}
+	/* End of body */
 
 	outbytes += smtp_write(sock, ".");
 	(void)alarm((unsigned) MAXWAIT);
@@ -1714,7 +1750,7 @@
 		j = 0;
 
 		add = 1;
-		while(argv[i][++j] != (char)NULL) {
+		while(argv[i][++j] != '\0') {
 			switch(argv[i][j]) {
 #ifdef INET6
 			case '6':
@@ -1732,14 +1768,14 @@
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
@@ -1749,14 +1785,14 @@
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
@@ -1847,14 +1883,14 @@
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
@@ -1866,14 +1902,14 @@
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
