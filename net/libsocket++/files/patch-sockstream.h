--- socket++/sockstream.h.orig	Fri Jan 16 22:35:55 2004
+++ socket++/sockstream.h	Fri Jan 16 22:39:09 2004
@@ -151,10 +151,12 @@
   enum msgflag {
     msg_oob		= MSG_OOB,
     msg_peek	        = MSG_PEEK,
-    msg_dontroute	= MSG_DONTROUTE,
 
 #if !(defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__APPLE__))
+    msg_dontroute	= MSG_DONTROUTE,
     msg_maxiovlen	= MSG_MAXIOVLEN
+#else
+    msg_dontroute	= MSG_DONTROUTE
 #endif
   };
   enum shuthow {
