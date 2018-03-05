https://github.com/domoticz/domoticz/commit/388c7b51716c

--- webserver/proxyclient.cpp.orig	2017-07-30 10:19:41 UTC
+++ webserver/proxyclient.cpp
@@ -639,7 +639,7 @@ namespace http {
 		void CProxyManager::StartThread()
 		{
 			try {
-				boost::asio::ssl::context ctx(io_service, boost::asio::ssl::context::sslv23);
+				boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);
 				ctx.set_verify_mode(boost::asio::ssl::verify_none);
 
 				proxyclient.reset(new CProxyClient(io_service, ctx, m_pWebEm));
