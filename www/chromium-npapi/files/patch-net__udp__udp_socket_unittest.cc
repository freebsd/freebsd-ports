--- ./net/udp/udp_socket_unittest.cc.orig	2014-04-30 22:43:08.000000000 +0200
+++ ./net/udp/udp_socket_unittest.cc	2014-05-04 14:38:48.000000000 +0200
@@ -202,7 +202,7 @@
       client_entries, 5, NetLog::TYPE_SOCKET_ALIVE));
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // UDPSocketPrivate_Broadcast is disabled for OSX because it requires
 // root permissions on OSX 10.7+.
 TEST_F(UDPSocketTest, DISABLED_Broadcast) {
