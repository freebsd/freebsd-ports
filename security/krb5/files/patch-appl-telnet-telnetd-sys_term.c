--- appl/telnet/telnetd/sys_term.c.orig	Fri Nov 15 12:21:51 2002
+++ appl/telnet/telnetd/sys_term.c	Wed Apr  4 14:02:18 2007
@@ -1287,6 +1287,16 @@
 #endif
 #if	defined (AUTHENTICATION)
 	if (auth_level >= 0 && autologin == AUTH_VALID) {
+		if (name[0] == '-') {
+		    /* Authenticated and authorized to log in to an
+		       account starting with '-'?  Even if that
+		       unlikely case comes to pass, the current login
+		       program will not parse the resulting command
+		       line properly.  */
+		    syslog(LOG_ERR, "user name cannot start with '-'");
+		    fatal(net, "user name cannot start with '-'");
+		    exit(1);
+		}
 # if	!defined(NO_LOGIN_F)
 #if	defined(LOGIN_CAP_F)
 		argv = addarg(argv, "-F");
@@ -1377,11 +1387,19 @@
 	} else
 #endif
 	if (getenv("USER")) {
-		argv = addarg(argv, getenv("USER"));
+		char *user = getenv("USER");
+		if (user[0] == '-') {
+		    /* "telnet -l-x ..." */
+		    syslog(LOG_ERR, "user name cannot start with '-'");
+		    fatal(net, "user name cannot start with '-'");
+		    exit(1);
+		}
+		argv = addarg(argv, user);
 #if	defined(LOGIN_ARGS) && defined(NO_LOGIN_P)
 		{
 			register char **cpp;
 			for (cpp = environ; *cpp; cpp++)
+			    if ((*cpp)[0] != '-')
 				argv = addarg(argv, *cpp);
 		}
 #endif
