--- src/socket.cpp.orig	Thu Jan  2 22:08:06 2003
+++ src/socket.cpp	Wed Jan  8 07:58:47 2003
@@ -13,6 +13,9 @@
 #include <netdb.h>
 #include <fcntl.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
 
 #ifdef HAVE_INET_ATON
 #include <arpa/inet.h>
@@ -427,7 +430,11 @@
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
