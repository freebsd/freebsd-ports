--- pop3vscan.h.orig	Wed Jun 12 08:19:05 2002
+++ pop3vscan.h	Tue Jun  3 03:23:38 2003
@@ -28,6 +28,7 @@
 /* includes {{{1 */
 #include <syslog.h>	    /* do_log */
+#include <netinet/in.h>
 #include <arpa/inet.h>	    /* config */
 
 /* definitions {{{1 */
 #define PROGNAME		"POP3VScan"
