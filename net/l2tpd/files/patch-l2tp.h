
$FreeBSD$

--- l2tp.h.orig	Tue Jan 15 18:59:27 2002
+++ l2tp.h	Tue Oct 22 12:42:08 2002
@@ -20,7 +20,10 @@
 
 #define MAXSTRLEN 120		/* Maximum length of common strings */
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <termios.h>
 #include "osport.h"
 #include "scheduler.h"
