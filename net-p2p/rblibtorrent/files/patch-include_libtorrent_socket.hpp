--- include/libtorrent/socket.hpp.orig	Thu Aug  3 01:39:59 2006
+++ include/libtorrent/socket.hpp	Thu Aug  3 01:40:02 2006
@@ -75,7 +75,7 @@
 	using boost::asio::ipv4::host;
 	using boost::asio::deadline_timer;
 */
-	namespace asio = ::asio;
+//	namespace asio = ::asio;
 
 	using asio::ip::tcp;
 	using asio::ip::udp;
