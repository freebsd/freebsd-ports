--- src/socket.cpp.orig	Tue Jul 23 12:22:13 2002
+++ src/socket.cpp	Thu Aug  8 03:07:32 2002
@@ -13,6 +13,7 @@
 #include <netdb.h>
 #include <fcntl.h>
 #include <unistd.h>
+#include <osreldate.h>
 
 #ifdef HAVE_INET_ATON
 #include <arpa/inet.h>
@@ -304,6 +305,8 @@
   // Setup the local structure
 #ifdef USE_SOCKS5
   int sizeofSockaddr = sizeof(struct sockaddr_in);
+#elif __FreeBSD_version < 400013
+  int sizeofSockaddr = sizeof(struct sockaddr_in);
 #else
   socklen_t sizeofSockaddr = sizeof(struct sockaddr_in);
 #endif
@@ -416,7 +419,11 @@
     m_sRemoteAddr.sin_family = AF_INET;
 
     // if connect fails then call CloseConnection to clean up before returning
+#if __FreeBSD_version < 400013
+    int sizeofSockaddr = sizeof(struct sockaddr);
+#else
     socklen_t sizeofSockaddr = sizeof(struct sockaddr);
+#endif
     if (connect(m_nDescriptor, (struct sockaddr *)&m_sRemoteAddr, sizeofSockaddr) < 0)
     {
       // errno has been set
@@ -691,6 +698,8 @@
 void TCPSocket::RecvConnection(TCPSocket &newSocket)
 {
 #ifdef USE_SOCKS5
+  int sizeofSockaddr = sizeof(struct sockaddr_in);
+#elif __FreeBSD_version < 400013
   int sizeofSockaddr = sizeof(struct sockaddr_in);
 #else
   socklen_t sizeofSockaddr = sizeof(struct sockaddr_in);
