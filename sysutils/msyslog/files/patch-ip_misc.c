--- src/modules/ip_misc.c.orig	Thu Apr 26 19:09:26 2001
+++ src/modules/ip_misc.c	Sun May 13 16:30:57 2001
@@ -62,12 +62,6 @@
 #include "../modules.h"
 #include "../syslogd.h"
 
-/* recvfrom() and others like socklen_t, Irix doesn't provide it */   
-#ifndef HAVE_SOCKLEN_T
-  typedef int socklen_t;
-#endif
-
-
 #define TCP_KEEPALIVE 30	/* seconds to probe TCP connection */
 #define MSYSLOG_MAX_TCP_CLIENTS 100
 #define LISTENQ 35
