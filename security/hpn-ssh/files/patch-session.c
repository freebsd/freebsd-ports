--- session.c.orig	Sun Jun 10 17:22:44 2001
+++ session.c	Sun Jun 10 17:23:22 2001
@@ -514,6 +514,13 @@
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
@@ -628,6 +635,13 @@
 		/* Child.  Reinitialize the log because the pid has changed. */
 		log_init(__progname, options.log_level, options.log_facility, log_stderr);
 
+		/*
+		 * Using login and executing a specific "command" are mutually
+		 * exclusive, so turn off use_login if there's a command.
+		 */
+		if (command != NULL)
+			options.use_login = 0;
+
 		/* Close the master side of the pseudo tty. */
 		close(ptyfd);
 
@@ -707,6 +721,11 @@
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
@@ -767,6 +786,21 @@
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
 
@@ -1376,7 +1410,7 @@
 	 * initgroups, because at least on Solaris 2.3 it leaves file
 	 * descriptors open.
 	 */
-	for (i = 3; i < 64; i++)
+	for (i = 3; i < getdtablesize(); i++)
 		close(i);
 
 	/* Change current directory to the user\'s home directory. */
@@ -1400,6 +1434,28 @@
 	 * in this order).
 	 */
 	if (!options.use_login) {
+#ifdef __FreeBSD__
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
+#endif /* __FreeBSD__ */
 		/* ignore _PATH_SSH_USER_RC for subsystems */
 		if (!s->is_subsystem && (stat(_PATH_SSH_USER_RC, &st) >= 0)) {
 			snprintf(cmd, sizeof cmd, "%s -c '%s %s'",
