--- ssmtp.c.orig    2009-11-23 11:55:11.000000000 +0200
+++ ssmtp.c 2011-02-21 02:56:10.000000000 +0200
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
 
@@ -363,7 +382,7 @@
 	*linestart = False;
 
 	if((p = strchr(str, '\n'))) {
-		*p = (char)NULL;
+		*p = '\0';
 		*linestart = True;
 	}
 	return(leadingdot);
@@ -384,7 +403,7 @@
 		while(fgets(buf, sizeof(buf), fp)) {
 			/* Make comments invisible */
 			if((p = strchr(buf, '#'))) {
-				*p = (char)NULL;
+				*p = '\0';
 			}
 
 			/* Ignore malformed lines and comments */
@@ -519,11 +538,11 @@
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
 
@@ -548,7 +567,7 @@
 	(void)fprintf(stderr, "*** rcpt_parse(): str = [%s]\n", str);
 #endif
 
-	if((p = strdup(str)) == (char *)NULL) {
+	if((p = strdup(str)) == NULL) {
 		die("rcpt_parse(): strdup() failed");
 	}
 	q = p;
@@ -576,7 +595,7 @@
 		}
 
 		/* End of string? */
-		if(*(q + 1) == (char)NULL) {
+		if(*(q + 1) == '\0') {
 			got_addr = True;
 		}
 
@@ -584,7 +603,7 @@
 		if((*q == ',') && (in_quotes == False)) {
 			got_addr = True;
 
-			*q = (char)NULL;
+			*q = '\0';
 		}
 
 		if(got_addr) {
@@ -668,7 +687,7 @@
 	(void)fprintf(stderr, "header_save(): str = [%s]\n", str);
 #endif
 
-	if((p = strdup(str)) == (char *)NULL) {
+	if((p = strdup(str)) == NULL) {
 		die("header_save() -- strdup() failed");
 	}
 	ht->string = p;
@@ -676,7 +695,7 @@
 	if(strncasecmp(ht->string, "From:", 5) == 0) {
 #if 1
 		/* Hack check for NULL From: line */
-		if(*(p + 6) == (char)NULL) {
+		if(*(p + 6) == '\0') {
 			return;
 		}
 #endif
@@ -739,19 +758,19 @@
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
@@ -776,9 +795,9 @@
 						in_header = False;
 
 				default:
-						*q = (char)NULL;
+						*q = '\0';
 						if((q = strrchr(p, '\n'))) {
-							*q = (char)NULL;
+							*q = '\0';
 						}
 						header_save(p);
 
@@ -809,9 +828,9 @@
 						in_header = False;
 
 				default:
-						*q = (char)NULL;
+						*q = '\0';
 						if((q = strrchr(p, '\n'))) {
-							*q = (char)NULL;
+							*q = '\0';
 						}
 						header_save(p);
 
@@ -876,21 +895,27 @@
 		char *rightside;
 		/* Make comments invisible */
 		if((p = strchr(buf, '#'))) {
-			*p = (char)NULL;
+			/* check if # is a part of a param */
+			if((q = strchr(buf, '='))) { 
+				if ((int)(p-buf) < (int)(q-buf))
+					*p = '\0';
+			}
+			else
+				*p = '\0';
 		}
 
 		/* Ignore malformed lines and comments */
-		if(strchr(buf, '=') == (char *)NULL) continue;
+		if(strchr(buf, '=') == NULL) continue;
 
 		/* Parse out keywords */
 		p=firsttok(&begin, "= \t\n");
 		if(p){
 			rightside=begin;
-			q = firsttok(&begin, "= \t\n");
+			q = firsttok(&begin, " \t\n");
 		}
 		if(p && q) {
 			if(strcasecmp(p, "Root") == 0) {
-				if((root = strdup(q)) == (char *)NULL) {
+				if((root = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -904,7 +929,7 @@
 					port = atoi(r);
 				}
 
-				if((mailhost = strdup(q)) == (char *)NULL) {
+				if((mailhost = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -949,7 +974,7 @@
 					mail_domain = strdup(q);
 				}
 
-				if(mail_domain == (char *)NULL) {
+				if(mail_domain == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 				rewrite_domain = True;
@@ -1025,7 +1050,7 @@
 				}
 			}
 			else if(strcasecmp(p, "TLSCert") == 0) {
-				if((tls_cert = strdup(q)) == (char *)NULL) {
+				if((tls_cert = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -1036,7 +1061,7 @@
 #endif
 			/* Command-line overrides these */
 			else if(strcasecmp(p, "AuthUser") == 0 && !auth_user) {
-				if((auth_user = strdup(q)) == (char *)NULL) {
+				if((auth_user = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -1045,7 +1070,7 @@
 				}
 			}
 			else if(strcasecmp(p, "AuthPass") == 0 && !auth_pass) {
-				if((auth_pass = strdup(q)) == (char *)NULL) {
+				if((auth_pass = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -1054,7 +1079,7 @@
 				}
 			}
 			else if(strcasecmp(p, "AuthMethod") == 0 && !auth_method) {
-				if((auth_method = strdup(q)) == (char *)NULL) {
+				if((auth_method = strdup(q)) == NULL) {
 					die("parse_config() -- strdup() failed");
 				}
 
@@ -1107,11 +1132,11 @@
 #ifdef INET6
 	struct addrinfo hints, *ai0, *ai;
 	char servname[NI_MAXSERV];
-	int s;
+	int s = -1;
 #else
 	struct sockaddr_in name;
 	struct hostent *hent;
-	int i, s, namelen;
+	int i, s = -1, namelen;
 #endif
 
 #ifdef HAVE_SSL
@@ -1310,7 +1335,7 @@
 			buf[i++] = c;
 		}
 	}
-	buf[i] = (char)NULL;
+	buf[i] = '\0';
 
 	return(buf);
 }
@@ -1435,14 +1460,14 @@
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
 
@@ -1490,7 +1515,7 @@
 	/* Try to log in if username was supplied */
 	if(auth_user) {
 #ifdef MD5AUTH
-		if(auth_pass == (char *)NULL) {
+		if(auth_pass == NULL) {
 			auth_pass = strdup("");
 		}
 
@@ -1742,7 +1767,7 @@
 		j = 0;
 
 		add = 1;
-		while(argv[i][++j] != (char)NULL) {
+		while(argv[i][++j] != '\0') {
 			switch(argv[i][j]) {
 #ifdef INET6
 			case '6':
@@ -1760,14 +1785,14 @@
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
@@ -1777,14 +1802,14 @@
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
@@ -1875,14 +1900,14 @@
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
@@ -1894,14 +1919,14 @@
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
