--- src/modules/im_tcp.c.orig	Thu Jun 14 07:30:35 2001
+++ src/modules/im_tcp.c	Sun Jul  1 03:34:58 2001
@@ -61,6 +61,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/uio.h>
+#include <sys/param.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <errno.h>
@@ -71,11 +72,6 @@
 
 #include "../modules.h"
 #include "../syslogd.h"
-
-/* recvfrom() and others like socklen_t, Irix doesn't provide it */   
-#ifndef HAVE_SOCKLEN_T
-  typedef int socklen_t;
-#endif
 
 struct tcp_conn {
 	struct tcp_conn *next;
