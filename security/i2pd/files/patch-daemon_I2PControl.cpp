--- daemon/I2PControl.cpp.orig	2017-12-04 18:40:32 UTC
+++ daemon/I2PControl.cpp
@@ -35,7 +35,7 @@ namespace client
 	I2PControlService::I2PControlService (const std::string& address, int port):
 		m_IsRunning (false), m_Thread (nullptr),
 		m_Acceptor (m_Service, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(address), port)),
-		m_SSLContext (m_Service, boost::asio::ssl::context::sslv23),
+		m_SSLContext (boost::asio::ssl::context::sslv23),
 		m_ShutdownTimer (m_Service)
 	{
 		i2p::config::GetOption("i2pcontrol.password", m_Password);
