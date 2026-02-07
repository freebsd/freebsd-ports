Description: Various sanity- and security-related fixes.
 Buffer handling:
 - use snprintf() instead of strncpy() to ensure null-termination;
 - explicitly pass sizeof(var) as a second argument to snprintf() to
   protect against a variable definition changing in the future;
 - display the correct amount of failed-to-allocate memory.
 Fix a misspelling of TCPREMOTEIP that would prevent POP-before-SMTP.
 Enclose a write() into a loop so that it succeeds even for amounts
 too large to write at once.
 Display an error message if the execv() in exec_local() fails and
 propagate the error all the way up to main()'s exit code.
 Extract the indiargs as separate defines so that the port's Makefile may
 modify them easily.
 Mark two function parameters as unused.
 Fix a couple of const-related compiler warnings.
Forwarded: no
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2009-11-26

--- a/authvchkpw.c
+++ b/authvchkpw.c
@@ -54,6 +54,18 @@
 #define AUTH_SIZE 512
 #endif
 
+#ifndef __unused
+#ifdef __GNUC__
+#define __unused	__attribute__((unused))
+#else
+#define __unused
+#endif
+#endif
+
+#define PATH_IMAPLOGIN	VPOPMAILDIR"/sbin/imaplogin"
+#define PATH_AUTHVCHKPW	VPOPMAILDIR"/libexec/authlib/authvchkpw"
+#define PATH_IMAPD	VPOPMAILDIR"/bin/imapd"
+
 int             authlen = AUTH_SIZE;
 static int      exec_local(char **, char *, char *, struct vqpasswd *, char *);
 static char     hextab[] = "0123456789abcdef";
@@ -70,7 +82,7 @@
 }
 
 int
-pw_comp(char *testlogin, char *password, char *challenge, char *response)
+pw_comp(char *login __unused, char *password, char *challenge, char *response)
 {
 	unsigned char   digest[16];
 	unsigned char   digascii[33];
@@ -105,7 +117,7 @@
  * getEnvConfigStr
  */
 void
-getEnvConfigStr(char **source, char *envname, char *defaultValue)
+getEnvConfigStr(char **source, const char *envname, char *defaultValue)
 {
 	if (!(*source = getenv(envname)))
 		*source = defaultValue;
@@ -115,8 +127,8 @@
 int
 Login_Tasks(pw, user, ServiceType)
 	struct passwd  *pw;
-	const char     *user;
-	char           *ServiceType;
+	char           *user;
+	const char     *ServiceType __unused;
 {
 	char           *domain, *ptr;
 	char            fqemail[MAX_BUFF];
@@ -131,17 +143,17 @@
 
 	if (!pw)
 		return(1);
-	lowerit((char *) user);
+	lowerit(user);
 	lowerit(pw->pw_name);
 	if (!(ptr = strchr(user, '@')))
 	{
 		getEnvConfigStr(&domain, "DEFAULT_DOMAIN", DEFAULT_DOMAIN);
 		lowerit(domain);
-		snprintf(fqemail, MAX_BUFF, "%s@%s", user, domain);
+		snprintf(fqemail, sizeof(fqemail), "%s@%s", user, domain);
 	} else
 	{
 		domain = ptr + 1;
-		strncpy(fqemail, user, MAX_BUFF);
+		snprintf(fqemail, sizeof(fqemail), "%s", user);
 		*ptr = 0;
 	}
 	if (access(pw->pw_dir, F_OK))
@@ -155,7 +167,7 @@
 #ifdef MIN_LOGIN_INTERVAL
 	last_time = vget_lastauth(pw, domain);
 #endif
-	if (!(ptr = getenv("TCPERMOTEIP")))
+	if (!(ptr = getenv("TCPREMOTEIP")))
 		ptr = "0.0.0.0";
 	vset_lastauth(pw->pw_name, domain, ptr);
 #ifdef MIN_LOGIN_INTERVAL
@@ -168,10 +180,12 @@
 }
 
 int
-pipe_exec(char **argv, char *tmpbuf, int len)
+pipe_exec(char **argv, char *tmpbuf, size_t len)
 {
 	int             pipe_fd[2];
 	void            (*pstat) ();
+	ssize_t         n;
+	size_t          pos;
 
 	if ((pstat = signal(SIGPIPE, SIG_IGN)) == SIG_ERR)
 	{
@@ -194,7 +208,10 @@
 		close(pipe_fd[0]);
 	if(pipe_fd[1] != 3 && pipe_fd[1] != 4)
 		close(pipe_fd[1]);
-	if(write(4, tmpbuf, len) != len)
+	pos = 0;
+	while(pos < len && (n = write(4, tmpbuf + pos, len - pos)) > 0)
+		pos += n;
+	if (pos < len)
 	{
 		fprintf(stderr, "pipe_exec: %s: %s\n", argv[1], strerror(errno));
 		signal(SIGPIPE, pstat);
@@ -212,13 +229,13 @@
 {
 	char           *buf, *tmpbuf, *login, *challenge, *crypt_pass,
 				   *prog_name, *service, *service_type;
-	char            user[AUTH_SIZE], domain[AUTH_SIZE], Email[MAX_BUFF];
+	char            user[MAX_BUFF], domain[MAX_BUFF], Email[MAX_BUFF];
 	int             count, offset;
 	uid_t           uid;
 	gid_t           gid;
 	struct vqpasswd  *pw;
-	char           *(indiargs[]) = { VPOPMAILDIR"/sbin/imaplogin", VPOPMAILDIR"/libexec/authlib/authvchkpw",
-					VPOPMAILDIR"/bin/imapd", "Maildir", 0 };
+	char           *(indiargs[]) = { PATH_IMAPLOGIN, PATH_AUTHVCHKPW,
+					PATH_IMAPD, "Maildir", 0 };
 
 	if ((prog_name = strrchr(argv[0], '/')))
 		prog_name++;
@@ -272,7 +289,7 @@
 	}
 	if (!(buf = calloc(1, (offset + 1) * sizeof(char))))
 	{
-		fprintf(stderr, "%s: malloc-%d: %s\n", prog_name, authlen + 1, strerror(errno));
+		fprintf(stderr, "%s: malloc-%d: %s\n", prog_name, offset + 1, strerror(errno));
 		return(1);
 	}
 	memcpy(buf, tmpbuf, offset);
@@ -325,7 +342,7 @@
 		pipe_exec(argv, buf, offset);
 		return (1);
 	}
-	snprintf(Email, MAX_BUFF, "%s@%s", user, domain);
+	snprintf(Email, sizeof(Email), "%s@%s", user, domain);
     if (vauth_open(0))
 	{
 		fprintf(stderr, "%s: inquery: %s\n", prog_name, strerror(errno));
@@ -402,8 +419,7 @@
 		pipe_exec(argv, buf, offset);
 		return (1);
 	}
-	exec_local(argv + argc - 2, login, domain, pw, service);
-	return(0);
+	return(exec_local(argv + argc - 2, login, domain, pw, service));
 }
 
 static int
@@ -418,7 +434,7 @@
 #endif
 	for (cptr = TheUser, ptr = userid;*ptr && *ptr != '@';*cptr++ = *ptr++);
 	*cptr = 0;
-	strncpy(TmpBuf, service, MAX_BUFF);
+	snprintf(TmpBuf, sizeof(TmpBuf), "%s", service);
 	if ((ptr = strrchr(TmpBuf, ':')))
 		*ptr = 0;
 	status = Login_Tasks(pw, userid, TmpBuf);
@@ -428,22 +444,22 @@
 		return(1);
 	}
 	close_connection();
-	snprintf(Maildir, MAX_BUFF, "%s/Maildir", status == 2 ? "/mail/tmp" : pw->pw_dir);
+	snprintf(Maildir, sizeof(Maildir), "%s/Maildir", status == 2 ? "/mail/tmp" : pw->pw_dir);
 	if (access(pw->pw_dir, F_OK) || access(Maildir, F_OK) || chdir(pw->pw_dir))
 	{
 		fprintf(stderr, "chdir: %s: %s\n", pw->pw_dir, strerror(errno));
 		return(1);
 	}
-	snprintf(authenv1, MAX_BUFF, "AUTHENTICATED=%s", userid);
-	snprintf(authenv2, MAX_BUFF, "AUTHADDR=%s@%s", TheUser, TheDomain);
-	snprintf(authenv3, MAX_BUFF, "AUTHFULLNAME=%s", pw->pw_gecos);
+	snprintf(authenv1, sizeof(authenv1), "AUTHENTICATED=%s", userid);
+	snprintf(authenv2, sizeof(authenv2), "AUTHADDR=%s@%s", TheUser, TheDomain);
+	snprintf(authenv3, sizeof(authenv3), "AUTHFULLNAME=%s", pw->pw_gecos);
 #ifdef USE_MAILDIRQUOTA	
 	size_limit = parse_quota(pw->pw_shell, &count_limit);
-	snprintf(authenv4, MAX_BUFF, "MAILDIRQUOTA=%"PRIu64"S,%"PRIu64"C", size_limit, count_limit);
+	snprintf(authenv4, sizeof(authenv4), "MAILDIRQUOTA=%"PRIu64"S,%"PRIu64"C", size_limit, count_limit);
 #else
-	snprintf(authenv4, MAX_BUFF, "MAILDIRQUOTA=%sS", pw->pw_shell);
+	snprintf(authenv4, sizeof(authenv4), "MAILDIRQUOTA=%sS", pw->pw_shell);
 #endif
-	snprintf(authenv5, MAX_BUFF, "MAILDIR=%s", Maildir);
+	snprintf(authenv5, sizeof(authenv5), "MAILDIR=%s", Maildir);
 	putenv(authenv1);
 	putenv(authenv2);
 	putenv(authenv3);
@@ -451,6 +467,7 @@
 	putenv(authenv5);
 	close_connection();
 	execv(argv[0], argv);
+	fprintf(stderr, "pipe_exec: %s: %s\n", argv[0], strerror(errno));
 	return(1);
 }
 
