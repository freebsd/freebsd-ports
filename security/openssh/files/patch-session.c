--- session.c.orig	Wed Sep 17 10:53:49 2003
+++ session.c	Wed Sep 17 10:59:52 2003
@@ -58,6 +58,13 @@
 #include "session.h"
 #include "monitor_wrap.h"
 
+#ifdef __FreeBSD__
+#include <libutil.h>
+#include <syslog.h>
+#include <time.h>
+#define _PATH_CHPASS "/usr/bin/passwd"
+#endif /* __FreeBSD__ */
+
 /* func */
 
 Session *session_new(void);
@@ -421,6 +428,9 @@
 do_exec_no_pty(Session *s, const char *command)
 {
 	pid_t pid;
+#ifdef USE_PAM
+	const char *shorttty;
+#endif /* USE_PAM */
 
 #ifdef USE_PIPES
 	int pin[2], pout[2], perr[2];
@@ -439,6 +449,20 @@
 	if (s == NULL)
 		fatal("do_exec_no_pty: no session");
 
+#ifdef USE_PAM
+	/* check if we have a pathname in the ttyname */
+	shorttty = rindex( s->tty, '/' );
+	if (shorttty != NULL ) {
+		/* use only the short filename to check */
+		shorttty ++;
+	} else {
+		/* nothing found, use the whole name found */
+		shorttty = s->tty;
+	}
+	do_pam_session(s->pw->pw_name, shorttty);
+	do_pam_setcred();
+#endif /* USE_PAM */
+
 	session_proctitle(s);
 
 	/* Fork the child. */
@@ -449,6 +473,13 @@
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
@@ -643,6 +674,18 @@
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
@@ -665,10 +708,97 @@
 		    options.verify_reverse_mapping),
 		    (struct sockaddr *)&from, fromlen);
 
+#ifdef USE_PAM
+	/*
+	 * If password change is needed, do it now.
+	 * This needs to occur before the ~/.hushlogin check.
+	 */
+	if (pam_password_change_required()) {
+		print_pam_messages();
+		do_pam_chauthtok();
+	}
+	if (!check_quietlogin(s, command) && !pam_password_change_required())
+		print_pam_messages();
+#endif /* USE_PAM */
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
+			log("%s Password expired - forcing change",
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
+#ifndef USE_PAM
+	if (pw->pw_expire) {
+		if (tv.tv_sec >= pw->pw_expire) {
+			(void)printf(
+			    "Sorry -- your account has expired.\n");
+			log(
+	   "LOGIN %.200s REFUSED (EXPIRED) FROM %.200s ON TTY %.200s",
+				pw->pw_name, get_remote_name_or_ip(utmp_len,
+				options.verify_reverse_mapping), s->tty);
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
+		log(
+	       "LOGIN %.200s REFUSED (TTY) FROM %.200s ON TTY %.200s",
+		    pw->pw_name, get_remote_name_or_ip(utmp_len,
+			options.verify_reverse_mapping), s->tty);
+		exit(254);
+	}
+#endif /* HAVE_LOGIN_CAP */
+
 	if (check_quietlogin(s, command))
 		return;
 
-	if (options.print_lastlog && s->last_login_time != 0) {
+	/*
+	 * If the user has logged in before, display the time of last
+	 * login. However, don't display anything extra if a command
+	 * has been specified (so that ssh can be used to execute
+	 * commands on a remote machine without users knowing they
+	 * are going to another machine). Login(1) will do this for
+	 * us as well, so check if login(1) is used
+	 */
+	if (command == NULL && options.print_lastlog &&
+	    s->last_login_time != 0 &&
+	    !options.use_login) {
 		time_string = ctime(&s->last_login_time);
 		if (strchr(time_string, '\n'))
 			*strchr(time_string, '\n') = 0;
@@ -679,7 +809,30 @@
 			    s->hostname);
 	}
 
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
@@ -695,9 +848,9 @@
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
@@ -724,10 +877,10 @@
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
 
@@ -739,7 +892,7 @@
 child_set_env(char ***envp, u_int *envsizep, const char *name,
 	const char *value)
 {
-	u_int i, namelen;
+	u_int i, namelen, envsize;
 	char **env;
 
 	/*
@@ -757,12 +910,14 @@
 		xfree(env[i]);
 	} else {
 		/* New variable.  Expand if necessary. */
-		if (i >= (*envsizep) - 1) {
-			if (*envsizep >= 1000)
+		envsize = *envsizep;
+		if (i >= envsize - 1) {
+			if (envsize >= 1000)
 				fatal("child_set_env: too many env vars,"
 				    " skipping: %.100s", name);
-			(*envsizep) += 50;
-			env = (*envp) = xrealloc(env, (*envsizep) * sizeof(char *));
+			envsize += 50;
+			env = (*envp) = xrealloc(env, envsize * sizeof(char *));
+			*envsizep = envsize;
 		}
 		/* Need to set the NULL pointer at end of array beyond the new slot. */
 		env[i + 1] = NULL;
@@ -818,12 +973,39 @@
 	fclose(f);
 }
 
+void copy_environment(char **source, char ***env, u_int *envsize)
+{
+	char *var_name, *var_val;
+	int i;
+
+	if (source == NULL)
+		return;
+
+	for(i = 0; source[i] != NULL; i++) {
+		var_name = xstrdup(source[i]);
+		if ((var_val = strstr(var_name, "=")) == NULL) {
+			xfree(var_name);
+			continue;
+		}
+		*var_val++ = '\0';
+
+		debug3("Copy environment: %s=%s", var_name, var_val);
+		child_set_env(env, envsize, var_name, var_val);
+		
+		xfree(var_name);
+	}
+}
+
 static char **
 do_setup_env(Session *s, const char *shell)
 {
 	char buf[256];
 	u_int i, envsize;
 	char **env, *laddr;
+#ifdef HAVE_LOGIN_CAP
+	extern char **environ;
+	char **senv, **var;
+#endif /* HAVE_LOGIN_CAP */
 	struct passwd *pw = s->pw;
 
 	/* Initialize the environment. */
@@ -831,6 +1013,11 @@
 	env = xmalloc(envsize * sizeof(char *));
 	env[0] = NULL;
 
+#ifdef __FreeBSD__
+	if (getenv("TZ"))
+		child_set_env(&env, &envsize, "TZ", getenv("TZ"));
+#endif /* __FreeBSD__ */
+
 	if (!options.use_login) {
 		/* Set basic environment. */
 		child_set_env(&env, &envsize, "USER", pw->pw_name);
@@ -851,9 +1038,21 @@
 
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
+			 xfree(*var);
+		xfree(environ);
+		environ = senv;
+#endif /* HAVE_LOGIN_CAP */
 	}
-	if (getenv("TZ"))
-		child_set_env(&env, &envsize, "TZ", getenv("TZ"));
 
 	/* Set custom environment options from RSA authentication. */
 	if (!options.use_login) {
@@ -903,6 +1102,10 @@
 		child_set_env(&env, &envsize, "KRB5CCNAME",
 		    s->authctxt->krb5_ticket_file);
 #endif
+#ifdef USE_PAM
+	/* Pull in any environment variables that may have been set by PAM. */
+	do_pam_environment(&env, &envsize);
+#endif /* USE_PAM */
 	if (auth_sock_name != NULL)
 		child_set_env(&env, &envsize, SSH_AUTHSOCKET_ENV_NAME,
 		    auth_sock_name);
@@ -1025,7 +1228,7 @@
 	if (getuid() == 0 || geteuid() == 0) {
 #ifdef HAVE_LOGIN_CAP
 		if (setusercontext(lc, pw, pw->pw_uid,
-		    (LOGIN_SETALL & ~LOGIN_SETPATH)) < 0) {
+		    (LOGIN_SETALL & ~(LOGIN_SETENV|LOGIN_SETPATH))) < 0) {
 			perror("unable to set user context");
 			exit(1);
 		}
@@ -1065,6 +1268,36 @@
 	exit(1);
 }
 
+#ifdef USE_PAM
+/*
+ * Sets any environment variables which have been specified by PAM
+ */
+void do_pam_environment(char ***env, int *envsize)
+{
+	char *equals, var_name[512], var_val[512];
+	char **pam_env;
+	int i;
+
+	if ((pam_env = fetch_pam_environment()) == NULL)
+		return;
+	
+	for(i = 0; pam_env[i] != NULL; i++) {
+		if ((equals = strstr(pam_env[i], "=")) == NULL)
+			continue;
+			
+		if (strlen(pam_env[i]) < (sizeof(var_name) - 1)) {
+			memset(var_name, '\0', sizeof(var_name));
+			memset(var_val, '\0', sizeof(var_val));
+
+			strncpy(var_name, pam_env[i], equals - pam_env[i]);
+			strcpy(var_val, equals + 1);
+
+			child_set_env(env, envsize, var_name, var_val);
+		}
+	}
+}
+#endif /* USE_PAM */
+
 /*
  * Performs common processing for the child, such as setting up the
  * environment, closing extra file descriptors, setting the user and group
@@ -1148,7 +1381,7 @@
 	 * initgroups, because at least on Solaris 2.3 it leaves file
 	 * descriptors open.
 	 */
-	for (i = 3; i < 64; i++)
+	for (i = 3; i < getdtablesize(); i++)
 		close(i);
 
 	/*
@@ -1178,6 +1411,31 @@
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
