--- TcpSocket.cpp.orig	2012-09-08 06:47:13 UTC
+++ TcpSocket.cpp
@@ -1283,7 +1283,7 @@ void TcpSocket::InitializeContext(const 
 	/* Create our context*/
 	if (m_client_contexts.find(context) == m_client_contexts.end())
 	{
-		const SSL_METHOD *meth = meth_in ? meth_in : SSLv3_method();
+		const SSL_METHOD *meth = meth_in ? meth_in : SSLv23_method();
 		m_ssl_ctx = m_client_contexts[context] = SSL_CTX_new(const_cast<SSL_METHOD *>(meth));
 		SSL_CTX_set_mode(m_ssl_ctx, SSL_MODE_AUTO_RETRY|SSL_MODE_ENABLE_PARTIAL_WRITE);
 	}
@@ -1339,7 +1339,7 @@ void TcpSocket::InitializeContext(const 
 	/* Create our context*/
 	if (m_server_contexts.find(context) == m_server_contexts.end())
 	{
-		const SSL_METHOD *meth = meth_in ? meth_in : SSLv3_method();
+		const SSL_METHOD *meth = meth_in ? meth_in : SSLv23_method();
 		m_ssl_ctx = m_server_contexts[context] = SSL_CTX_new(const_cast<SSL_METHOD *>(meth));
 		SSL_CTX_set_mode(m_ssl_ctx, SSL_MODE_AUTO_RETRY|SSL_MODE_ENABLE_PARTIAL_WRITE);
 		// session id
