--- src/socket.cpp.orig	Tue Jul 23 07:22:13 2002
+++ src/socket.cpp	Mon Dec 16 19:21:03 2002
@@ -13,6 +13,9 @@
 #include <netdb.h>
 #include <fcntl.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
 
 #ifdef HAVE_INET_ATON
 #include <arpa/inet.h>
@@ -304,6 +307,8 @@
   // Setup the local structure
 #ifdef USE_SOCKS5
   int sizeofSockaddr = sizeof(struct sockaddr_in);
+#elif defined(__FreeBSD__) && __FreeBSD_version < 400013
+  int sizeofSockaddr = sizeof(struct sockaddr_in);
 #else
   socklen_t sizeofSockaddr = sizeof(struct sockaddr_in);
 #endif
@@ -416,7 +421,11 @@
     m_sRemoteAddr.sin_family = AF_INET;
 
     // if connect fails then call CloseConnection to clean up before returning
+#if defined(__FreeBSD__) && __FreeBSD_version < 400013
+    int sizeofSockaddr = sizeof(struct sockaddr);
+#else
     socklen_t sizeofSockaddr = sizeof(struct sockaddr);
+#endif
     if (connect(m_nDescriptor, (struct sockaddr *)&m_sRemoteAddr, sizeofSockaddr) < 0)
     {
       // errno has been set
@@ -691,6 +700,8 @@
 void TCPSocket::RecvConnection(TCPSocket &newSocket)
 {
 #ifdef USE_SOCKS5
+  int sizeofSockaddr = sizeof(struct sockaddr_in);
+#elif defined(__FreeBSD__) && __FreeBSD_version < 400013
   int sizeofSockaddr = sizeof(struct sockaddr_in);
 #else
   socklen_t sizeofSockaddr = sizeof(struct sockaddr_in);
