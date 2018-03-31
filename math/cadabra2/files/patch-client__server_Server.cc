--- client_server/Server.cc.orig	2018-03-31 19:40:16 UTC
+++ client_server/Server.cc
@@ -466,7 +466,7 @@ void Server::run() 
 		
 		wserver.init_asio();
 		wserver.set_reuse_addr(true);
-		wserver.listen(0);
+		wserver.listen(websocketpp::lib::asio::ip::tcp::v4(), 0); // makes up for a failed assumption that IPv6 is mapped into IPv4: (see net.inet6.ip6.v6only=0)
 		wserver.start_accept();
 		websocketpp::lib::asio::error_code ec;
 		auto p = wserver.get_local_endpoint(ec);
