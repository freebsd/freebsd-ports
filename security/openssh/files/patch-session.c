--- session.c.orig	Fri Mar  8 06:11:56 2002
+++ session.c	Fri Mar  8 06:15:32 2002
@@ -57,6 +57,12 @@
 #include "canohost.h"
 #include "session.h"
 
+#ifdef __FreeBSD__
+#include <libutil.h>
+#include <syslog.h>
+#include <time.h>
+#endif /* __FreeBSD__ */
+
 /* types */
 
 #define TTYSZ 64
@@ -394,6 +400,13 @@
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
@@ -499,6 +512,14 @@
 
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
 
@@ -589,6 +610,11 @@
 	time_t last_login_time;
 	struct passwd * pw = s->pw;
 	pid_t pid = getpid();
+#ifdef HAVE_LOGIN_CAP
+	FILE *f;
+	char buf[256];
+	char *fname;
+#endif /* HAVE_LOGIN_CAP */
 
 	/*
 	 * Get IP address of client. If the connection is not a socket, let
@@ -629,6 +655,21 @@
 			printf("Last login: %s from %s\r\n", time_string, hostname);
 	}
 
+#ifdef HAVE_LOGIN_CAP
+	if (!options.use_login) {
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
 	do_motd();
 }
 
@@ -775,6 +816,10 @@
 	env[0] = NULL;
 
 	if (!options.use_login) {
+#ifdef HAVE_LOGIN_CAP
+		char *var;
+#endif /* HAVE_LOGIN_CAP */
+
 		/* Set basic environment. */
 		child_set_env(&env, &envsize, "USER", pw->pw_name);
 		child_set_env(&env, &envsize, "LOGNAME", pw->pw_name);
@@ -782,6 +827,12 @@
 #ifdef HAVE_LOGIN_CAP
 		(void) setusercontext(lc, pw, pw->pw_uid, LOGIN_SETPATH);
 		child_set_env(&env, &envsize, "PATH", getenv("PATH"));
+		var= login_getcapstr(lc, "lang", NULL, NULL);
+		if ( var ) child_set_env(&env, &envsize, "LANG", var);
+		var= login_getcapstr(lc, "charset", NULL, NULL);
+		if ( var ) child_set_env(&env, &envsize, "MM_CHARSET", var);
+		var= login_getcapstr(lc, "timezone", NULL, NULL);
+		if ( var ) child_set_env(&env, &envsize, "TZ", var);
 #else
 		child_set_env(&env, &envsize, "PATH", _PATH_STDPATH);
 #endif
@@ -793,8 +844,13 @@
 		/* Normal systems set SHELL by default. */
 		child_set_env(&env, &envsize, "SHELL", shell);
 	}
+#ifdef HAVE_LOGIN_CAP
+#else /* HAVE_LOGIN_CAP */
+               if (getenv("TZ"))
+                       child_set_env(&env, &envsize, "TZ", getenv("TZ"));
 	if (getenv("TZ"))
 		child_set_env(&env, &envsize, "TZ", getenv("TZ"));
+#endif /* HAVE_LOGIN_CAP */
 
 	/* Set custom environment options from RSA authentication. */
 	if (!options.use_login) {
@@ -1057,7 +1113,7 @@
 	 * initgroups, because at least on Solaris 2.3 it leaves file
 	 * descriptors open.
 	 */
-	for (i = 3; i < 64; i++)
+	for (i = 3; i < getdtablesize(); i++)
 		close(i);
 
 	/*
@@ -1087,6 +1143,31 @@
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
