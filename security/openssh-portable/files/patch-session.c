--- session.c.orig	2008-11-07 09:06:00.463747629 +0800
+++ session.c	2008-11-07 23:35:15.063890103 +0800
@@ -884,6 +884,24 @@
 {
 	FILE *f;
 	char buf[256];
+#ifdef HAVE_LOGIN_CAP
+	const char *fname;
+#endif
+
+#ifdef HAVE_LOGIN_CAP
+	fname = login_getcapstr(lc, "copyright", NULL, NULL);
+	if (fname != NULL && (f = fopen(fname, "r")) != NULL) {
+		while (fgets(buf, sizeof(buf), f) != NULL)
+			fputs(buf, stdout);
+			fclose(f);
+	} else
+#endif /* HAVE_LOGIN_CAP */
+		(void)printf("%s\n\t%s %s\n",
+	"Copyright (c) 1980, 1983, 1986, 1988, 1990, 1991, 1993, 1994",
+	"The Regents of the University of California. ",
+	"All rights reserved.");
+
+	(void)printf("\n");
 
 	if (options.print_motd) {
 #ifdef HAVE_LOGIN_CAP
@@ -1113,6 +1131,9 @@
 	struct passwd *pw = s->pw;
 #ifndef HAVE_LOGIN_CAP
 	char *path = NULL;
+#else
+	extern char **environ;
+	char **senv, **var;
 #endif
 
 	/* Initialize the environment. */
@@ -1134,6 +1155,9 @@
 	}
 #endif
 
+	if (getenv("TZ"))
+		child_set_env(&env, &envsize, "TZ", getenv("TZ"));
+
 #ifdef GSSAPI
 	/* Allow any GSSAPI methods that we've used to alter
 	 * the childs environment as they see fit
@@ -1153,11 +1177,22 @@
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
@@ -1178,15 +1213,9 @@
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
@@ -1452,6 +1481,9 @@
 void
 do_setusercontext(struct passwd *pw)
 {
+#ifdef CHROOT
+	char *user_dir, *new_root;
+#endif /* CHROOT */
 	char *chroot_path, *tmp;
 
 #ifdef WITH_SELINUX
@@ -1477,8 +1509,25 @@
 			do_pam_setcred(use_privsep);
 		}
 # endif /* USE_PAM */
+#ifdef CHROOT
+		user_dir = xstrdup(pw->pw_dir);
+		new_root = user_dir + 1;
+
+		while((new_root = strchr(new_root, '.')) != NULL) {
+			new_root--;
+			if(strncmp(new_root, "/./", 3) == 0) {
+				*new_root = '\0';
+				new_root += 2;
+				if(chroot(user_dir) != 0)
+					fatal("Couldn't chroot to user directory %s. %s", user_dir, strerror(errno));
+				pw->pw_dir = new_root;
+				break;
+			}
+			new_root += 2;
+		}
+#endif /* CHROOT */
 		if (setusercontext(lc, pw, pw->pw_uid,
-		    (LOGIN_SETALL & ~(LOGIN_SETPATH|LOGIN_SETUSER))) < 0) {
+		    (LOGIN_SETALL & ~(LOGIN_SETPATH|LOGIN_SETUSER|LOGIN_SETENV))) < 0) {
 			perror("unable to set user context");
 			exit(1);
 		}
@@ -1736,6 +1785,10 @@
 	 */
 	environ = env;
 
+#ifdef HAVE_LOGIN_CAP
+	r = login_getcapbool(lc, "requirehome", 0);
+	login_close(lc);
+#endif
 #if defined(KRB5) && defined(USE_AFS)
 	/*
 	 * At this point, we check to see if AFS is active and if we have
@@ -1765,9 +1818,6 @@
 	/* Change current directory to the user's home directory. */
 	if (chdir(pw->pw_dir) < 0) {
 		/* Suppress missing homedir warning for chroot case */
-#ifdef HAVE_LOGIN_CAP
-		r = login_getcapbool(lc, "requirehome", 0);
-#endif
 		if (r || options.chroot_directory == NULL)
 			fprintf(stderr, "Could not chdir to home "
 			    "directory %s: %s\n", pw->pw_dir,
