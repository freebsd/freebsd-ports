--- src/modules/im_tcp.c.orig	Thu Apr 26 00:43:50 2001
+++ src/modules/im_tcp.c	Sun May 13 00:49:45 2001
@@ -72,11 +72,6 @@
 #include "../modules.h"
 #include "../syslogd.h"
 
-/* recvfrom() and others like socklen_t, Irix doesn't provide it */   
-#ifndef HAVE_SOCKLEN_T
-  typedef int socklen_t;
-#endif
-
 struct tcp_conn {
 	struct tcp_conn *next;
 	int		 fd;
