--- ./src/httpd/core.c.orig	2010-09-29 18:21:00.000000000 +0200
+++ ./src/httpd/core.c	2010-09-29 18:21:49.000000000 +0200
@@ -1529,8 +1529,7 @@
 		   (filter == EVFILT_VNODE) ? "EVFILT_VNODE" :
 		   (filter == EVFILT_PROC) ? "EVFILT_PROC" :
 		   (filter == EVFILT_SIGNAL) ? "EVFILT_SIGNAL" :
-		   (filter == EVFILT_TIMER) ? "EVFILT_TIMER" :
-		   (filter == EVFILT_NETDEV) ? "EVFILT_NETDEV" : "???");
+		   (filter == EVFILT_TIMER) ? "EVFILT_TIMER" : "???");
 
 	return str;
 }
