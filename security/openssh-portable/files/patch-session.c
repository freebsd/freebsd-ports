--- session.c.orig	Fri Sep  1 02:38:37 2006
+++ session.c	Sat Sep 30 19:32:06 2006
@@ -776,6 +776,24 @@
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
@@ -1004,6 +1022,9 @@
 	struct passwd *pw = s->pw;
 #ifndef HAVE_LOGIN_CAP
 	char *path = NULL;
+#else
+	extern char **environ;
+	char **senv, **var;
 #endif
 
 	/* Initialize the environment. */
@@ -1025,6 +1046,9 @@
 	}
 #endif
 
+	if (getenv("TZ"))
+		child_set_env(&env, &envsize, "TZ", getenv("TZ"));
+
 #ifdef GSSAPI
 	/* Allow any GSSAPI methods that we've used to alter
 	 * the childs environment as they see fit
@@ -1044,11 +1068,22 @@
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
@@ -1069,15 +1104,9 @@
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
@@ -1287,6 +1316,10 @@
 void
 do_setusercontext(struct passwd *pw)
 {
+#ifdef CHROOT
+	char *user_dir;
+	char *new_root;
+#endif /* CHROOT */
 #ifndef HAVE_CYGWIN
 	if (getuid() == 0 || geteuid() == 0)
 #endif /* HAVE_CYGWIN */
@@ -1314,10 +1347,31 @@
 		}
 # endif /* USE_PAM */
 		if (setusercontext(lc, pw, pw->pw_uid,
-		    (LOGIN_SETALL & ~LOGIN_SETPATH)) < 0) {
+		    (LOGIN_SETALL & ~(LOGIN_SETENV|LOGIN_SETPATH))) < 0) {
 			perror("unable to set user context");
 			exit(1);
 		}
+#ifdef CHROOT
+		user_dir = xstrdup(pw->pw_dir);
+		new_root = user_dir + 1;
+
+		while((new_root = strchr(new_root, '.')) != NULL) {
+			new_root--;
+			if(strncmp(new_root, "/./", 3) == 0) {
+				*new_root = '\0';
+				new_root += 2;
+
+				if(chroot(user_dir) != 0)
+					fatal("Couldn't chroot to user directory %s", user_dir);
+				pw->pw_dir = new_root;
+				break;
+			}
+
+			new_root += 2;
+		}
+#endif /* CHROOT */
+		/* Permanently switch to the desired uid. */
+		permanently_set_uid(pw);
 #else
 # if defined(HAVE_GETLUID) && defined(HAVE_SETLUID)
 		/* Sets login uid for accounting */
@@ -1472,6 +1526,9 @@
 	char *argv[10];
 	const char *shell, *shell0, *hostname = NULL;
 	struct passwd *pw = s->pw;
+#ifdef HAVE_LOGIN_CAP
+	int lc_requirehome;
+#endif
 
 	/* remove hostkey from the child's memory */
 	destroy_sensitive_data();
@@ -1559,6 +1616,10 @@
 	 */
 	environ = env;
 
+#ifdef HAVE_LOGIN_CAP
+	lc_requirehome = login_getcapbool(lc, "requirehome", 0);
+	login_close(lc);
+#endif
 #if defined(KRB5) && defined(USE_AFS)
 	/*
 	 * At this point, we check to see if AFS is active and if we have
@@ -1590,7 +1651,7 @@
 		fprintf(stderr, "Could not chdir to home directory %s: %s\n",
 		    pw->pw_dir, strerror(errno));
 #ifdef HAVE_LOGIN_CAP
-		if (login_getcapbool(lc, "requirehome", 0))
+		if (lc_requirehome)
 			exit(1);
 #endif
 	}
