--- src/modules/im_tcp.c.orig	Sat Jan  4 15:42:05 2003
+++ src/modules/im_tcp.c	Sat Jan  4 15:42:41 2003
@@ -61,6 +61,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/uio.h>
+#include <sys/param.h>
 #include <ctype.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -72,11 +73,6 @@
 
 #include "../modules.h"
 #include "../syslogd.h"
-
-/* recvfrom() and others like socklen_t, Irix doesn't provide it */   
-#ifndef HAVE_SOCKLEN_T
-  typedef int socklen_t;
-#endif
 
 struct tcp_conn {
 	struct tcp_conn *next;
