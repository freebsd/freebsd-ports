--- ./net/udp/udp_socket_unittest.cc.orig	2014-04-24 22:35:54.000000000 +0200
+++ ./net/udp/udp_socket_unittest.cc	2014-04-24 23:23:46.000000000 +0200
@@ -202,7 +202,7 @@
       client_entries, 5, NetLog::TYPE_SOCKET_ALIVE));
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // UDPSocketPrivate_Broadcast is disabled for OSX because it requires
 // root permissions on OSX 10.7+.
 TEST_F(UDPSocketTest, DISABLED_Broadcast) {
