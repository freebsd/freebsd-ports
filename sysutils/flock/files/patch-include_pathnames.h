--- include/pathnames.h.orig	2016-03-09 10:44:05 UTC
+++ include/pathnames.h
@@ -46,10 +46,14 @@
 #define	_PATH_MAILDIR		"/var/spool/mail"
 #endif
 #define	_PATH_MOTDFILE		"/etc/motd"
+#ifndef _PATH_NOLOGIN
 #define	_PATH_NOLOGIN		"/etc/nologin"
+#endif
 #define	_PATH_VAR_NOLOGIN	"/var/run/nologin"
 
+#ifndef _PATH_LOGIN
 #define _PATH_LOGIN		"/bin/login"
+#endif
 #define _PATH_SHUTDOWN		"/sbin/shutdown"
 
 #define _PATH_TERMCOLORS_DIRNAME "terminal-colors.d"
