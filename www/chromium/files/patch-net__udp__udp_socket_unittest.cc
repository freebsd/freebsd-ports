--- net/udp/udp_socket_unittest.cc.orig	2014-10-10 08:54:16 UTC
+++ net/udp/udp_socket_unittest.cc
@@ -204,7 +204,7 @@
       client_entries, 5, NetLog::TYPE_SOCKET_ALIVE));
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // UDPSocketPrivate_Broadcast is disabled for OSX because it requires
 // root permissions on OSX 10.7+.
 TEST_F(UDPSocketTest, DISABLED_Broadcast) {
