--- l2tp.h.orig	Mon Aug 19 20:26:23 2002
+++ l2tp.h	Tue Nov 12 13:00:09 2002
@@ -21,7 +21,10 @@
 
 #define MAXSTRLEN 120           /* Maximum length of common strings */
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <termios.h>
 #include "osport.h"
 #include "scheduler.h"
@@ -211,6 +214,7 @@
 extern int ppd;
 extern int switch_io;           /* jz */
 extern int control_fd;
+extern int control_fdw;
 extern int start_pppd (struct call *c, struct ppp_opts *);
 extern void magic_lac_dial (void *);
 extern int get_entropy (char *, int);
