--- src/socket.cc.orig	Tue Aug 31 15:37:52 2004
+++ src/socket.cc	Tue Oct 12 15:03:29 2004
@@ -190,7 +190,7 @@
 #endif
 	status_ = SOCKET_STATUS_OK;
 	return 1;
-};
+}
 
 
 gint
