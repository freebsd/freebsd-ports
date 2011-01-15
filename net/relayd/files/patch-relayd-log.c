--- relayd/log.c.orig	2011-01-15 00:27:09.012456298 +0100
+++ relayd/log.c	2011-01-15 00:39:01.553947279 +0100
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
@@ -192,9 +200,15 @@
 	case HCE_ICMP_WRITE_TIMEOUT:
 		return ("icmp write timeout");
 		break;
-	case HCE_TCP_CONNECT_ERROR:
-		return ("tcp connect error");
+	case HCE_TCP_SOCKET_ERROR:
+		return ("tcp socket error");
+		break;
+	case HCE_TCP_SOCKET_LIMIT:
+		return ("tcp socket limit");
 		break;
+	case HCE_TCP_SOCKET_OPTION:
+		return ("tcp socket option");
+ 		break;
 	case HCE_TCP_CONNECT_FAIL:
 		return ("tcp connect failed");
 		break;
