--- SocketHandler.h.orig	2008-11-30 02:32:59.000000000 -0200
+++ SocketHandler.h	2008-11-30 02:33:51.000000000 -0200
@@ -36,6 +36,7 @@
 
 class SocketHandler
 {
+protected:
 	/** Map type for holding file descriptors/socket object pointers. */
 	typedef std::map<SOCKET,Socket *> socket_m;
 
