--- src/socket.cpp.orig	Mon Jun 16 19:09:46 2003
+++ src/socket.cpp	Mon Aug  2 16:05:55 2004
@@ -20,6 +20,9 @@
 #include <netdb.h>
 #include <fcntl.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
 
 #ifdef HAVE_INET_ATON
 #include <arpa/inet.h>
@@ -49,7 +52,6 @@
 #ifdef USE_SOCKS5
 
 #define SOCKS
-#define INCLUDE_PROTOTYPES
 extern "C" {
 #include <socks.h>
 }
@@ -489,7 +491,11 @@
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
