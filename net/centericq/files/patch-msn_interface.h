--- blip-0.1/msn_interface.h.orig	Mon Dec  9 20:31:41 2002
+++ blip-0.1/msn_interface.h	Thu Oct 23 20:02:19 2003
@@ -25,6 +25,8 @@
 
 void ext_got_info(msnconn * conn, syncinfo * data);
 
+void ext_debug( char *msg );
+
 void ext_latest_serial(msnconn * conn, int serial);
 
 void ext_got_GTC(msnconn * conn, char c);
@@ -78,6 +80,8 @@
 	Return:         Nothing
 */
 int ext_connect_socket(const char * server, int port);
+
+int ext_connect_socket_ssl(const char * server, int port);
 
 int ext_server_socket(int port);
 
