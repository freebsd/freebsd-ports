--- libi2pd/Reseed.cpp.orig	2017-12-04 18:40:32 UTC
+++ libi2pd/Reseed.cpp
@@ -522,7 +522,7 @@ namespace data
 		boost::asio::io_service service;
 		boost::system::error_code ecode;
 
-		boost::asio::ssl::context ctx(service, boost::asio::ssl::context::sslv23);
+		boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);
 		ctx.set_verify_mode(boost::asio::ssl::context::verify_none);
 		boost::asio::ssl::stream<boost::asio::ip::tcp::socket> s(service, ctx);
 
