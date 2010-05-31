--- relayd/log.c.orig	2010-05-31 08:55:55.644112693 +0200
+++ relayd/log.c	2010-05-31 08:55:50.789959404 +0200
@@ -45,6 +45,7 @@
 #include "relayd.h"
 
 int	 debug;
+int	 verbose;
 
 void	 vlog(int, const char *, va_list);
 void	 logit(int, const char *, ...);
@@ -55,6 +56,7 @@
 	extern char	*__progname;
 
 	debug = n_debug;
+	verbose = n_debug;
 
 	if (!debug)
 		openlog(__progname, LOG_PID | LOG_NDELAY, LOG_DAEMON);
@@ -63,6 +65,12 @@
 }
 
 void
+log_verbose(int v)
+{
+	verbose = v;
+}
+
+void
 logit(int pri, const char *fmt, ...)
 {
 	va_list	ap;
@@ -141,7 +149,7 @@
 {
 	va_list	 ap;
 
-	if (debug > 1) {
+	if (verbose > 1) {
 		va_start(ap, emsg);
 		vlog(LOG_DEBUG, emsg, ap);
 		va_end(ap);
