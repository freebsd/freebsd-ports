--- src/lib/dhcp/iface_mgr.cc.orig	2024-07-25 08:50:58 UTC
+++ src/lib/dhcp/iface_mgr.cc
@@ -1034,7 +1034,7 @@ IfaceMgr::getLocalAddress(const IOAddress& remote_addr
     }
 
     // Create socket that will be used to connect to remote endpoint.
-    boost::asio::io_service io_service;
+    boost::asio::io_context io_service;
     boost::asio::ip::udp::socket sock(io_service);
 
     boost::system::error_code err_code;
