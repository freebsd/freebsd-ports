--- src/modules/im_udp.c.orig	Thu Apr 26 00:43:50 2001
+++ src/modules/im_udp.c	Sun May 13 23:44:03 2001
@@ -58,12 +58,6 @@
 #include "../modules.h"
 #include "../syslogd.h"
 
-/* recvfrom() and others like socklen_t, Irix doesn't provide it */   
-#ifndef HAVE_SOCKLEN_T
-  typedef int socklen_t;
-#endif
-
-
 /*
  * get messge
  *
