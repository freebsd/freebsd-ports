--- src/modules/im_udp.c.orig	Sat Mar 23 18:14:04 2002
+++ src/modules/im_udp.c	Sat Mar 23 18:14:24 2002
@@ -58,11 +58,6 @@
 #include "../modules.h"
 #include "../syslogd.h"
 
-/* recvfrom() and others like socklen_t, Irix doesn't provide it */
-#ifndef HAVE_SOCKLEN_T
-  typedef int socklen_t;
-#endif
-
 struct im_udp_ctx {
 	int	flags;
 };
