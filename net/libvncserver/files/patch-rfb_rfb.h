--- rfb/rfb.h.orig	2017-07-05 07:45:47 UTC
+++ rfb/rfb.h
@@ -43,7 +43,7 @@ extern "C"
 #include <string.h>
 #include <rfb/rfbproto.h>
 
-#if defined(ANDROID) || defined(LIBVNCSERVER_HAVE_ANDROID)
+#if defined(ANDROID) || defined(LIBVNCSERVER_HAVE_ANDROID) || defined(__FreeBSD__)
 #include <arpa/inet.h>
 #include <sys/select.h>
 #endif
@@ -265,6 +265,8 @@ typedef struct _rfbScreenInfo
     rfbBool autoPort;
     int port;
     SOCKET listenSock;
+    SOCKET unixSock;
+    const char *unixSockPath;
     int maxSock;
     int maxFd;
 #ifdef WIN32
