--- session.c.orig	Thu Aug 12 14:40:25 2004
+++ session.c	Tue Sep 21 19:48:42 2004
@@ -66,6 +66,11 @@
 #include "ssh-gss.h"
 #endif
 
+#ifdef __FreeBSD__
+#include <syslog.h>
+#define _PATH_CHPASS "/usr/bin/passwd"
+#endif /* __FreeBSD__ */
+
 /* func */
 
 Session *session_new(void);
@@ -410,6 +415,13 @@
 		log_init(__progname, options.log_level, options.log_facility, log_stderr);
 
 		/*
+		 * Using login and executing a specific "command" are mutually
+		 * exclusive, so turn off use_login if there's a command.
+		 */
+		if (command != NULL)
+			options.use_login = 0;
+
+		/*
 		 * Create a new session and process group since the 4.4BSD
 		 * setlogin() affects the entire process group.
 		 */
@@ -526,6 +538,9 @@
 {
 	int fdout, ptyfd, ttyfd, ptymaster;
 	pid_t pid;
+#if defined(USE_PAM)
+	const char *shorttty;
+#endif
 
 	if (s == NULL)
 		fatal("do_exec_pty: no session");
@@ -546,6 +561,14 @@
 
 		/* Child.  Reinitialize the log because the pid has changed. */
 		log_init(__progname, options.log_level, options.log_facility, log_stderr);
+
+		/*
+		 * Using login and executing a specific "command" are mutually
+		 * exclusive, so turn off use_login if there's a command.
+		 */
+		if (command != NULL)
+			options.use_login = 0;
+
 		/* Close the master side of the pseudo tty. */
 		close(ptyfd);
 
@@ -692,6 +715,18 @@
 	struct sockaddr_storage from;
 	struct passwd * pw = s->pw;
 	pid_t pid = getpid();
+#ifdef HAVE_LOGIN_CAP
+	FILE *f;
+	char buf[256];
+	char *fname;
+	const char *shorttty;
+#endif /* HAVE_LOGIN_CAP */
+#ifdef __FreeBSD__
+#define DEFAULT_WARN  (2L * 7L * 86400L)  /* Two weeks */
+	char *newcommand;
+	struct timeval tv;
+	time_t warntime = DEFAULT_WARN;
+#endif /* __FreeBSD__ */
 
 	/*
 	 * Get IP address of client. If the connection is not a socket, let
@@ -727,12 +762,101 @@
 	}
 #endif
 
+#ifdef __FreeBSD__
+	if (pw->pw_change || pw->pw_expire)
+		(void)gettimeofday(&tv, NULL);
+#ifdef HAVE_LOGIN_CAP
+	warntime = login_getcaptime(lc, "warnpassword",
+				    DEFAULT_WARN, DEFAULT_WARN);
+#endif /* HAVE_LOGIN_CAP */
+	/*
+	 * If the password change time is set and has passed, give the
+	 * user a password expiry notice and chance to change it.
+	 */
+	if (pw->pw_change != 0) {
+		if (tv.tv_sec >= pw->pw_change) {
+			(void)printf(
+			    "Sorry -- your password has expired.\n");
+			logit("%s Password expired - forcing change",
+			    pw->pw_name);
+			if (newcommand != NULL)
+				xfree(newcommand);
+			newcommand = xstrdup(_PATH_CHPASS);
+		} else if (pw->pw_change - tv.tv_sec < warntime &&
+			   !check_quietlogin(s, command))
+			(void)printf(
+			    "Warning: your password expires on %s",
+			     ctime(&pw->pw_change));
+	}
+
+#ifndef USE_PAM
+	if (pw->pw_expire) {
+		if (tv.tv_sec >= pw->pw_expire) {
+			(void)printf(
+			    "Sorry -- your account has expired.\n");
+			logit(
+	   "LOGIN %.200s REFUSED (EXPIRED) FROM %.200s ON TTY %.200s",
+				pw->pw_name, get_remote_name_or_ip(utmp_len,
+				options.use_dns), s->tty);
+			exit(254);
+		} else if (pw->pw_expire - tv.tv_sec < warntime &&
+			   !check_quietlogin(s, command))
+			(void)printf(
+			    "Warning: your account expires on %s",
+			     ctime(&pw->pw_expire));
+	}
+#endif /* !USE_PAM */
+#endif /* __FreeBSD__ */
+
+#ifdef HAVE_LOGIN_CAP
+	/* check if we have a pathname in the ttyname */
+	shorttty = rindex( s->tty, '/' );
+	if (shorttty != NULL ) {
+		/* use only the short filename to check */
+		shorttty ++;
+	} else {
+		/* nothing found, use the whole name found */
+		shorttty = s->tty;
+	}
+	if (!auth_ttyok(lc, shorttty)) {
+		(void)printf("Permission denied.\n");
+		logit(
+	       "LOGIN %.200s REFUSED (TTY) FROM %.200s ON TTY %.200s",
+		    pw->pw_name, get_remote_name_or_ip(utmp_len,
+			options.use_dns), s->tty);
+		exit(254);
+	}
+#endif /* HAVE_LOGIN_CAP */
+
 	if (check_quietlogin(s, command))
 		return;
 
 	display_loginmsg();
 
-	do_motd();
+#ifdef HAVE_LOGIN_CAP
+	if (command == NULL &&
+	    !options.use_login) {
+		fname = login_getcapstr(lc, "copyright", NULL, NULL);
+		if (fname != NULL && (f = fopen(fname, "r")) != NULL) {
+			while (fgets(buf, sizeof(buf), f) != NULL)
+				fputs(buf, stdout);
+			fclose(f);
+		} else
+			(void)printf("%s\n\t%s %s\n",
+	"Copyright (c) 1980, 1983, 1986, 1988, 1990, 1991, 1993, 1994",
+	    "The Regents of the University of California. ",
+	    "All rights reserved.");
+	}
+#endif /* HAVE_LOGIN_CAP */
+
+	/*
+	 * Print /etc/motd unless a command was specified or printing
+	 * it was disabled in server options or login(1) will be
+	 * used.  Note that some machines appear to print it in
+	 * /etc/profile or similar.
+	 */
+	if (command == NULL && !options.use_login)
+		do_motd();
 }
 
 /*
@@ -748,9 +872,9 @@
 #ifdef HAVE_LOGIN_CAP
 		f = fopen(login_getcapstr(lc, "welcome", "/etc/motd",
 		    "/etc/motd"), "r");
-#else
+#else /* !HAVE_LOGIN_CAP */
 		f = fopen("/etc/motd", "r");
-#endif
+#endif /* HAVE_LOGIN_CAP */
 		if (f) {
 			while (fgets(buf, sizeof(buf), f))
 				fputs(buf, stdout);
@@ -777,10 +901,10 @@
 #ifdef HAVE_LOGIN_CAP
 	if (login_getcapbool(lc, "hushlogin", 0) || stat(buf, &st) >= 0)
 		return 1;
-#else
+#else /* HAVE_LOGIN_CAP */
 	if (stat(buf, &st) >= 0)
 		return 1;
-#endif
+#endif /* HAVE_LOGIN_CAP */
 	return 0;
 }
 
@@ -967,6 +1091,10 @@
 	char buf[256];
 	u_int i, envsize;
 	char **env, *laddr, *path = NULL;
+#ifdef HAVE_LOGIN_CAP
+	extern char **environ;
+	char **senv, **var;
+#endif /* HAVE_LOGIN_CAP */
 	struct passwd *pw = s->pw;
 
 	/* Initialize the environment. */
@@ -974,6 +1102,9 @@
 	env = xmalloc(envsize * sizeof(char *));
 	env[0] = NULL;
 
+	/* Moved up to resove confict with gsssapi patches */
+	if (getenv("TZ"))
+		child_set_env(&env, &envsize, "TZ", getenv("TZ"));
 #ifdef HAVE_CYGWIN
 	/*
 	 * The Windows environment contains some setting which are
@@ -1032,9 +1163,21 @@
 
 		/* Normal systems set SHELL by default. */
 		child_set_env(&env, &envsize, "SHELL", shell);
+#ifdef HAVE_LOGIN_CAP
+		senv = environ;
+		environ = xmalloc(sizeof(char *));
+		*environ = NULL;
+		if (setusercontext(lc, pw, pw->pw_uid,
+			LOGIN_SETENV|LOGIN_SETPATH) < 0) {
+			perror("unable to set user context enviroment");
+		}
+		copy_environment(environ, &env, &envsize);
+		for (var = environ; *var != NULL; ++var)
+			xfree(*var);
+		xfree(environ);
+		environ = senv;
+#endif /* HAVE_LOGIN_CAP */
 	}
-	if (getenv("TZ"))
-		child_set_env(&env, &envsize, "TZ", getenv("TZ"));
 
 	/* Set custom environment options from RSA authentication. */
 	if (!options.use_login) {
@@ -1234,6 +1377,12 @@
 void
 do_setusercontext(struct passwd *pw)
 {
+
+#ifdef CHROOT
+	char *user_dir;
+	char *new_root;
+#endif /* CHROOT */
+
 #ifndef HAVE_CYGWIN
 	if (getuid() == 0 || geteuid() == 0)
 #endif /* HAVE_CYGWIN */
@@ -1254,10 +1403,30 @@
 		}
 # endif /* USE_PAM */
 		if (setusercontext(lc, pw, pw->pw_uid,
-		    (LOGIN_SETALL & ~LOGIN_SETPATH)) < 0) {
+		    (LOGIN_SETALL & ~(LOGIN_SETENV|LOGIN_SETPATH|LOGIN_SETUSER))) < 0) {
 			perror("unable to set user context");
 			exit(1);
 		}
+#ifdef CHROOT
+	user_dir = xstrdup(pw->pw_dir);
+	new_root = user_dir + 1;
+
+	while((new_root = strchr(new_root, '.')) != NULL) {
+		new_root--;
+		if(strncmp(new_root, "/./", 3) == 0) {
+			*new_root = '\0';
+			new_root += 2;
+
+			if(chroot(user_dir) != 0)
+				fatal("Couldn't chroot to user directory %s", user_dir);
+			pw->pw_dir = new_root;
+			break;
+		}
+
+		new_root += 2;
+	}
+#endif /* CHROOT */
+	permanently_set_uid(pw);
 #else
 # if defined(HAVE_GETLUID) && defined(HAVE_SETLUID)
 		/* Sets login uid for accounting */
@@ -1284,7 +1453,16 @@
 		 * Reestablish them here.
 		 */
 		if (options.use_pam) {
-			do_pam_session();
+			/* check if we have a pathname in the ttyname */
+			shorttty = rindex( s->tty, '/' );
+			if (shorttty != NULL ) {
+				/* use only the short filename to check */
+				shorttty ++;
+			} else {
+				/* nothing found, use the whole name found */
+				shorttty = s->tty;
+			}
+			do_pam_session(s->pw->pw_name, shorttty);
 			do_pam_setcred(0);
 		}
 # endif /* USE_PAM */
@@ -1374,7 +1552,7 @@
 	 * initgroups, because at least on Solaris 2.3 it leaves file
 	 * descriptors open.
 	 */
-	for (i = 3; i < 64; i++)
+	for (i = 3; i < getdtablesize(); i++)
 		close(i);
 }
 
@@ -1503,6 +1681,31 @@
 			exit(1);
 #endif
 	}
+
+#ifdef __FreeBSD__
+  	if (!options.use_login) {
+		/*
+		 * If the password change time is set and has passed, give the
+		 * user a password expiry notice and chance to change it.
+		 */
+		if (pw->pw_change != 0) {
+			struct timeval tv;
+
+			(void)gettimeofday(&tv, NULL);
+			if (tv.tv_sec >= pw->pw_change) {
+				(void)printf(
+				    "Sorry -- your password has expired.\n");
+				syslog(LOG_INFO,
+				    "%s Password expired - forcing change",
+				    pw->pw_name);
+				if (system("/usr/bin/passwd") != 0) {
+					perror("/usr/bin/passwd");
+					exit(1);
+				}
+			}
+		}
+	}
+#endif /* __FreeBSD__ */
 
 	if (!options.use_login)
 		do_rc_files(s, shell);
