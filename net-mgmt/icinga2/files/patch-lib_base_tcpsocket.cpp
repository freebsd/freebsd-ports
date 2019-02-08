--- lib/base/tcpsocket.cpp.orig	2019-02-08 13:14:32 UTC
+++ lib/base/tcpsocket.cpp
@@ -91,6 +91,9 @@ void TcpSocket::Bind(const String& node, const String&
 
 		const int optTrue = 1;
 		setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<const char *>(&optTrue), sizeof(optTrue));
+#ifndef _WIN32
+		setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, reinterpret_cast<const char *>(&optTrue), sizeof(optTrue));
+#endif /* _WIN32 */
 
 		int rc = bind(fd, info->ai_addr, info->ai_addrlen);
 
