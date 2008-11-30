--- SocketHandler.h.orig	2008-11-30 02:37:01.000000000 -0200
+++ SocketHandler.h	2008-11-30 02:37:09.000000000 -0200
@@ -49,6 +49,7 @@
 	\ingroup basic */
 class SocketHandler
 {
+protected:
 	/** Map type for holding file descriptors/socket object pointers. */
 	typedef std::map<SOCKET,Socket *> socket_m;
 
