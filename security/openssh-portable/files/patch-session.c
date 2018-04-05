------------------------------------------------------------------------
r99055 | des | 2002-06-29 04:21:58 -0700 (Sat, 29 Jun 2002) | 6 lines
Changed paths:
   M /head/crypto/openssh/session.c

Make sure the environment variables set by setusercontext() are passed on
to the child process.

Reviewed by:    ache
Sponsored by:   DARPA, NAI Labs


--- session.c.orig	2018-04-01 22:38:28.000000000 -0700
+++ session.c	2018-04-03 13:56:49.599400000 -0700
@@ -982,6 +982,9 @@ do_setup_env(struct ssh *ssh, Session *s, const char *
 	struct passwd *pw = s->pw;
 #if !defined (HAVE_LOGIN_CAP) && !defined (HAVE_CYGWIN)
 	char *path = NULL;
+#else
+	extern char **environ;
+	char **senv, **var;
 #endif
 
 	/* Initialize the environment. */
@@ -1003,6 +1006,9 @@ do_setup_env(struct ssh *ssh, Session *s, const char *
 	}
 #endif
 
+	if (getenv("TZ"))
+		child_set_env(&env, &envsize, "TZ", getenv("TZ"));
+
 #ifdef GSSAPI
 	/* Allow any GSSAPI methods that we've used to alter
 	 * the childs environment as they see fit
@@ -1020,11 +1026,21 @@ do_setup_env(struct ssh *ssh, Session *s, const char *
 	child_set_env(&env, &envsize, "LOGIN", pw->pw_name);
 #endif
 	child_set_env(&env, &envsize, "HOME", pw->pw_dir);
+	snprintf(buf, sizeof buf, "%.200s/%.50s", _PATH_MAILDIR, pw->pw_name);
+	child_set_env(&env, &envsize, "MAIL", buf);
 #ifdef HAVE_LOGIN_CAP
-	if (setusercontext(lc, pw, pw->pw_uid, LOGIN_SETPATH) < 0)
-		child_set_env(&env, &envsize, "PATH", _PATH_STDPATH);
-	else
-		child_set_env(&env, &envsize, "PATH", getenv("PATH"));
+	child_set_env(&env, &envsize, "PATH", _PATH_STDPATH);
+	child_set_env(&env, &envsize, "TERM", "su");
+	senv = environ;
+	environ = xmalloc(sizeof(char *));
+	*environ = NULL;
+	(void) setusercontext(lc, pw, pw->pw_uid,
+	    LOGIN_SETENV|LOGIN_SETPATH);
+	copy_environment(environ, &env, &envsize);
+	for (var = environ; *var != NULL; ++var)
+		free(*var);
+	free(environ);
+	environ = senv;
 #else /* HAVE_LOGIN_CAP */
 # ifndef HAVE_CYGWIN
 	/*
@@ -1044,15 +1060,9 @@ do_setup_env(struct ssh *ssh, Session *s, const char *
 # endif /* HAVE_CYGWIN */
 #endif /* HAVE_LOGIN_CAP */
 
-	snprintf(buf, sizeof buf, "%.200s/%.50s", _PATH_MAILDIR, pw->pw_name);
-	child_set_env(&env, &envsize, "MAIL", buf);
-
 	/* Normal systems set SHELL by default. */
 	child_set_env(&env, &envsize, "SHELL", shell);
 
-	if (getenv("TZ"))
-		child_set_env(&env, &envsize, "TZ", getenv("TZ"));
-
 	/* Set custom environment options from pubkey authentication. */
 	if (options.permit_user_env) {
 		for (n = 0 ; n < auth_opts->nenv; n++) {
@@ -1331,7 +1341,7 @@ do_setusercontext(struct passwd *pw)
 	if (platform_privileged_uidswap()) {
 #ifdef HAVE_LOGIN_CAP
 		if (setusercontext(lc, pw, pw->pw_uid,
-		    (LOGIN_SETALL & ~(LOGIN_SETPATH|LOGIN_SETUSER))) < 0) {
+		    (LOGIN_SETALL & ~(LOGIN_SETENV|LOGIN_SETPATH|LOGIN_SETUSER))) < 0) {
 			perror("unable to set user context");
 			exit(1);
 		}
