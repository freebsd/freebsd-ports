r56266 | dinoex | 2002-03-17 14:24:24 -0600 (Sun, 17 Mar 2002) | 4 lines
Changed paths:
   M /head/security/hpn-ssh/Makefile
   M /head/security/hpn-ssh/files/patch-auth.c
   A /head/security/hpn-ssh/files/patch-auth1.c
   A /head/security/hpn-ssh/files/patch-auth2.c
   M /head/security/hpn-ssh/files/patch-session.c
   M /head/security/openssh-portable/Makefile
   M /head/security/openssh-portable/files/patch-auth.c
   A /head/security/openssh-portable/files/patch-auth1.c
   A /head/security/openssh-portable/files/patch-auth2.c
   M /head/security/openssh-portable/files/patch-session.c

Merged patches for HAVE_LOGIN_CAP from stable

PR:             35904

--- session.c.orig	2011-07-21 18:55:33.883559116 +0200
+++ session.c	2011-07-21 19:02:17.789294035 +0200
@@ -1125,6 +1143,9 @@
 	struct passwd *pw = s->pw;
 #if !defined (HAVE_LOGIN_CAP) && !defined (HAVE_CYGWIN)
 	char *path = NULL;
+#else
+	extern char **environ;
+	char **senv, **var;
 #endif
 
 	/* Initialize the environment. */
@@ -1146,6 +1167,9 @@
 	}
 #endif
 
+	if (getenv("TZ"))
+		child_set_env(&env, &envsize, "TZ", getenv("TZ"));
+
 #ifdef GSSAPI
 	/* Allow any GSSAPI methods that we've used to alter
 	 * the childs environment as they see fit
@@ -1165,11 +1189,22 @@
 		child_set_env(&env, &envsize, "LOGIN", pw->pw_name);
 #endif
 		child_set_env(&env, &envsize, "HOME", pw->pw_dir);
+		snprintf(buf, sizeof buf, "%.200s/%.50s",
+			 _PATH_MAILDIR, pw->pw_name);
+		child_set_env(&env, &envsize, "MAIL", buf);
 #ifdef HAVE_LOGIN_CAP
-		if (setusercontext(lc, pw, pw->pw_uid, LOGIN_SETPATH) < 0)
-			child_set_env(&env, &envsize, "PATH", _PATH_STDPATH);
-		else
-			child_set_env(&env, &envsize, "PATH", getenv("PATH"));
+		child_set_env(&env, &envsize, "PATH", _PATH_STDPATH);
+		child_set_env(&env, &envsize, "TERM", "su");
+		senv = environ;
+		environ = xmalloc(sizeof(char *));
+		*environ = NULL;
+		(void) setusercontext(lc, pw, pw->pw_uid,
+		    LOGIN_SETENV|LOGIN_SETPATH);
+		copy_environment(environ, &env, &envsize);
+		for (var = environ; *var != NULL; ++var)
+			xfree(*var);
+		xfree(environ);
+		environ = senv;
 #else /* HAVE_LOGIN_CAP */
 # ifndef HAVE_CYGWIN
 		/*
@@ -1190,15 +1225,9 @@
 # endif /* HAVE_CYGWIN */
 #endif /* HAVE_LOGIN_CAP */
 
-		snprintf(buf, sizeof buf, "%.200s/%.50s",
-			 _PATH_MAILDIR, pw->pw_name);
-		child_set_env(&env, &envsize, "MAIL", buf);
-
 		/* Normal systems set SHELL by default. */
 		child_set_env(&env, &envsize, "SHELL", shell);
 	}
-	if (getenv("TZ"))
-		child_set_env(&env, &envsize, "TZ", getenv("TZ"));
 
 	/* Set custom environment options from RSA authentication. */
 	if (!options.use_login) {
@@ -1473,9 +1502,9 @@
 	platform_setusercontext(pw);
 
 	if (platform_privileged_uidswap()) {
 #ifdef HAVE_LOGIN_CAP
 		if (setusercontext(lc, pw, pw->pw_uid,
-		    (LOGIN_SETALL & ~(LOGIN_SETPATH|LOGIN_SETUSER))) < 0) {
+ 		    (LOGIN_SETALL & ~(LOGIN_SETPATH|LOGIN_SETUSER|LOGIN_SETENV))) < 0) {
 			perror("unable to set user context");
 			exit(1);
 		}
@@ -1700,6 +1729,10 @@
 	 */
 	environ = env;
 
+#ifdef HAVE_LOGIN_CAP
+	r = login_getcapbool(lc, "requirehome", 0);
+	login_close(lc);
+#endif
 #if defined(KRB5) && defined(USE_AFS)
 	/*
 	 * At this point, we check to see if AFS is active and if we have
@@ -1729,9 +1762,6 @@
 	/* Change current directory to the user's home directory. */
 	if (chdir(pw->pw_dir) < 0) {
 		/* Suppress missing homedir warning for chroot case */
-#ifdef HAVE_LOGIN_CAP
-		r = login_getcapbool(lc, "requirehome", 0);
-#endif
 		if (r || options.chroot_directory == NULL ||
 		    strcasecmp(options.chroot_directory, "none") == 0)
 			fprintf(stderr, "Could not chdir to home "
