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
@@ -1078,7 +1084,7 @@
 bool TCPSocket::SecureConnect()
 {
   pthread_mutex_init(&mutex_ssl, NULL);
-  m_pSSL = SSL_new(gSSL_CTX);
+  m_p_SSL = SSL_new(gSSL_CTX);
 #ifdef SSL_DEBUG
   m_pSSL->debug = 1;
 #endif
@@ -1111,7 +1117,7 @@
 {
   pthread_mutex_init(&mutex_ssl, NULL);
 
-  m_pSSL = SSL_new(gSSL_CTX);
+  m_p_SSL = SSL_new(gSSL_CTX);
   SSL_set_session(m_pSSL, NULL);
   SSL_set_fd(m_pSSL, m_nDescriptor);
   int i = SSL_accept(m_pSSL);
