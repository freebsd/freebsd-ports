--- src/bitcoin-cli.cpp.orig	2018-01-13 04:55:52 UTC
+++ src/bitcoin-cli.cpp
@@ -105,7 +105,7 @@ Object CallRPC(const string& strMethod, 
     // Connect to localhost
     bool fUseSSL = GetBoolArg("-rpcssl", false);
     boost::asio::io_service io_service;
-    boost::asio::ssl::context context(io_service, boost::asio::ssl::context::sslv23);
+    boost::asio::ssl::context context(boost::asio::ssl::context::sslv23);
     context.set_options(boost::asio::ssl::context::no_sslv2 | boost::asio::ssl::context::no_sslv3);
     boost::asio::ssl::stream<boost::asio::ip::tcp::socket> sslStream(io_service, context);
     SSLIOStreamDevice<boost::asio::ip::tcp> d(sslStream, fUseSSL);
